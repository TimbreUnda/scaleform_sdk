#!/usr/bin/env python3
"""
compare_images.py  -  Per-pixel comparison of two PPM (P6 binary) images.

Reads two PPM files, computes pixel-level differences, and outputs a JSON
result to stdout.

Writes alongside each PPM:
  - A .png version of the reference image
  - A .png version of the test image
  - A diff PPM + PNG (4x amplified, written only when mismatches exist)

Output JSON:
  { pass, rmse, maxDelta, mismatchCount, mismatchPercent, threshold, width, height }

Exit code: 0 = pass, 1 = fail/error.

No external dependencies - only Python stdlib (struct, zlib, math).
"""

import sys
import os
import struct
import zlib
import json
import math
import argparse


# ---------------------------------------------------------------------------
# PPM reader
# ---------------------------------------------------------------------------

def read_ppm(path):
    """Read a P6 binary PPM file. Returns (width, height, pixel_bytes)."""
    with open(path, 'rb') as f:
        data = f.read()

    idx = [0]  # mutable container so nested functions can modify it

    def skip():
        while idx[0] < len(data):
            b = data[idx[0]:idx[0] + 1]
            if b == b'#':
                while idx[0] < len(data) and data[idx[0]:idx[0] + 1] != b'\n':
                    idx[0] += 1
            elif b in (b' ', b'\t', b'\n', b'\r'):
                idx[0] += 1
            else:
                break

    def token():
        skip()
        start = idx[0]
        while idx[0] < len(data) and data[idx[0]:idx[0] + 1] not in (b' ', b'\t', b'\n', b'\r'):
            idx[0] += 1
        return data[start:idx[0]].decode('ascii')

    magic  = token()
    width  = int(token())
    height = int(token())
    maxval = int(token())

    if magic != 'P6':
        raise ValueError(f'Not a P6 PPM: {path!r} (magic={magic!r})')
    if maxval != 255:
        raise ValueError(f'Unsupported maxval {maxval} in {path!r} (only 255 supported)')

    idx[0] += 1  # skip exactly one whitespace byte after maxval
    pixels = data[idx[0]:]
    expected = width * height * 3
    if len(pixels) < expected:
        raise ValueError(
            f'PPM pixel data too short in {path!r}: expected {expected} bytes, got {len(pixels)}'
        )
    return width, height, pixels


# ---------------------------------------------------------------------------
# PNG writer (pure stdlib - struct + zlib, no Pillow required)
# ---------------------------------------------------------------------------

def write_png(path, width, height, rgb_bytes):
    """Write an RGB PNG file from raw RGB byte data (no external dependencies)."""

    def chunk(tag, data):
        c = tag + data
        return struct.pack('>I', len(data)) + c + struct.pack('>I', zlib.crc32(c) & 0xFFFFFFFF)

    # Apply filter type 0 (None) to each scanline
    row = width * 3
    raw = bytearray()
    for y in range(height):
        raw.append(0)  # filter type byte
        raw.extend(rgb_bytes[y * row:(y + 1) * row])

    with open(path, 'wb') as f:
        f.write(b'\x89PNG\r\n\x1a\n')
        f.write(chunk(b'IHDR', struct.pack('>IIBBBBB', width, height, 8, 2, 0, 0, 0)))
        f.write(chunk(b'IDAT', zlib.compress(bytes(raw), 6)))
        f.write(chunk(b'IEND', b''))


def ppm_to_png_path(ppm_path):
    return os.path.splitext(ppm_path)[0] + '.png'


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def main():
    ap = argparse.ArgumentParser(
        description='Compare two PPM images pixel by pixel; also writes PNG versions.'
    )
    ap.add_argument('reference',    help='Reference PPM image path')
    ap.add_argument('test',         help='Test PPM image path')
    ap.add_argument('--diff',       default='', help='Output diff PPM path')
    ap.add_argument('--threshold',  type=int, default=8,
                    help='Per-pixel sum-of-channels threshold for mismatch (default: 8)')
    args = ap.parse_args()

    try:
        rw, rh, rpx = read_ppm(args.reference)
    except Exception as e:
        print(json.dumps({'pass': False, 'error': f'Failed to read reference: {e}'}))
        sys.exit(1)

    try:
        tw, th, tpx = read_ppm(args.test)
    except Exception as e:
        print(json.dumps({'pass': False, 'error': f'Failed to read test: {e}'}))
        sys.exit(1)

    if rw != tw or rh != th:
        print(json.dumps({
            'pass':  False,
            'error': f'Dimension mismatch: reference={rw}x{rh}, test={tw}x{th}',
        }))
        sys.exit(1)

    w, h  = rw, rh
    n     = w * h
    sum_sq        = 0.0
    max_delta     = 0
    mismatch_count = 0
    diff_data     = bytearray(n * 3) if args.diff else None

    for i in range(n):
        o  = i * 3
        dr = abs(int(rpx[o])     - int(tpx[o]))
        dg = abs(int(rpx[o + 1]) - int(tpx[o + 1]))
        db = abs(int(rpx[o + 2]) - int(tpx[o + 2]))
        s  = dr + dg + db
        sum_sq += dr * dr + dg * dg + db * db
        if s > max_delta:
            max_delta = s
        if s > args.threshold:
            mismatch_count += 1
        if diff_data is not None:
            diff_data[o]     = min(255, dr * 4)
            diff_data[o + 1] = min(255, dg * 4)
            diff_data[o + 2] = min(255, db * 4)

    rmse         = math.sqrt(sum_sq / (n * 3))
    mismatch_pct = round(mismatch_count / n * 100, 4)
    passed       = mismatch_count == 0 or rmse <= args.threshold / 3.0

    # Write PNG versions of reference and test for easy viewing
    write_png(ppm_to_png_path(args.reference), w, h, bytes(rpx[:n * 3]))
    write_png(ppm_to_png_path(args.test),      w, h, bytes(tpx[:n * 3]))

    # Write diff PPM + PNG when there are any mismatches
    if diff_data is not None and mismatch_count > 0:
        diff_dir = os.path.dirname(os.path.abspath(args.diff))
        os.makedirs(diff_dir, exist_ok=True)
        with open(args.diff, 'wb') as f:
            f.write(f'P6\n{w} {h}\n255\n'.encode('ascii'))
            f.write(bytes(diff_data))
        write_png(ppm_to_png_path(args.diff), w, h, bytes(diff_data))

    result = {
        'pass':            passed,
        'rmse':            round(rmse, 4),
        'maxDelta':        max_delta,
        'mismatchCount':   mismatch_count,
        'mismatchPercent': mismatch_pct,
        'threshold':       args.threshold,
        'width':           w,
        'height':          h,
    }
    print(json.dumps(result))
    sys.exit(0 if passed else 1)


if __name__ == '__main__':
    main()
