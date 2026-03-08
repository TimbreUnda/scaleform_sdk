#!/usr/bin/env python3
"""
compare_reference.py  -  Compare committed reference images (no GPU needed).

Reads TestManifest.json and compares D3D11 vs Vulkan reference PNGs from
the Reference/ directory. Intended for CI where no GPU is available.

Can also compare live Vulkan captures against D3D11 reference when run
after CaptureVulkan with --vulkan-dir pointing to fresh captures.

Usage:
  compare_reference.py [--reference-dir Reference]
                       [--vulkan-dir Reference/vulkan]
                       [--threshold 8]
                       [--manifest TestManifest.json]

Exit code: 0 = all pass, 1 = any failure.
"""

import sys
import os
import json
import subprocess
import argparse

SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))


def main():
    ap = argparse.ArgumentParser(description='Compare reference images (no GPU needed)')
    ap.add_argument('--manifest', default='',
                    help='Path to TestManifest.json')
    ap.add_argument('--reference-dir', default='',
                    help='Root reference directory (default: Reference/)')
    ap.add_argument('--vulkan-dir', default='',
                    help='Vulkan captures directory (default: <reference-dir>/vulkan)')
    ap.add_argument('--threshold', type=int, default=8,
                    help='Per-pixel mismatch threshold (default: 8)')
    ap.add_argument('--diff-dir', default='',
                    help='Output directory for diff images (default: Output/Diff)')
    ap.add_argument('--exclude', nargs='*', default=[],
                    help='Test names to exclude from comparison')
    args = ap.parse_args()

    manifest_path = args.manifest or os.path.join(SCRIPT_DIR, 'TestManifest.json')
    reference_dir = args.reference_dir or os.path.join(SCRIPT_DIR, 'Reference')
    vulkan_dir    = args.vulkan_dir or os.path.join(reference_dir, 'vulkan')
    d3d11_dir     = os.path.join(reference_dir, 'd3d11')
    diff_dir      = args.diff_dir or os.path.join(SCRIPT_DIR, 'Output', 'Diff')
    compare_script = os.path.join(SCRIPT_DIR, 'compare_images.py')

    if not os.path.exists(manifest_path):
        print(f'ERROR: Manifest not found: {manifest_path}', file=sys.stderr)
        sys.exit(1)

    with open(manifest_path) as f:
        manifest = json.load(f)

    tests          = manifest.get('tests', [])
    default_frames = manifest.get('defaultFrames', [1, 10, 30, 60])

    all_results  = []
    passed_count = 0
    total_frames = 0
    failed_frames = 0

    exclude_set = set(args.exclude)
    skipped_count = 0
    for test in tests:
        name   = test['name']
        frames = sorted(test.get('frames', default_frames))

        if name in exclude_set:
            print(f'\n=== {name} === [SKIP — excluded]')
            skipped_count += 1
            continue

        print(f'\n=== {name} ===')
        test_pass = True

        for frame in frames:
            frame_str = f'{frame:04d}'
            ref_png   = os.path.join(d3d11_dir, name, f'frame_{frame_str}.png')
            vk_png    = os.path.join(vulkan_dir, name, f'frame_{frame_str}.png')
            diff_png  = os.path.join(diff_dir, 'd3d11_vs_vulkan', name, f'frame_{frame_str}_diff.png')

            total_frames += 1

            if not os.path.exists(ref_png):
                print(f'    Frame {frame}: [FAIL] missing D3D11 reference: {ref_png}')
                test_pass = False
                failed_frames += 1
                continue
            if not os.path.exists(vk_png):
                print(f'    Frame {frame}: [FAIL] missing Vulkan image: {vk_png}')
                test_pass = False
                failed_frames += 1
                continue

            os.makedirs(os.path.dirname(diff_png), exist_ok=True)
            cmd = [
                sys.executable, compare_script,
                ref_png, vk_png,
                '--diff', diff_png,
                '--threshold', str(args.threshold),
            ]
            result = subprocess.run(cmd, capture_output=True, text=True)
            try:
                cmp = json.loads(result.stdout)
            except Exception:
                err = result.stderr[:300] if result.stderr else '(no output)'
                cmp = {'pass': False, 'error': err}
                print(f'      compare_images error: {err}', file=sys.stderr)

            ok = cmp.get('pass', False)
            if not ok:
                test_pass = False
                failed_frames += 1

            status   = 'PASS' if ok else 'FAIL'
            rmse     = cmp.get('rmse', '?')
            mismatch = cmp.get('mismatchCount', '?')
            print(f'    Frame {frame}: [{status}]  rmse={rmse}  mismatch={mismatch}px')

        if test_pass:
            passed_count += 1
        print(f"  {name}: [{'PASS' if test_pass else 'FAIL'}]")
        all_results.append({'name': name, 'pass': test_pass})

    tested = len(tests) - skipped_count
    overall = passed_count == tested
    print(f'\n{"=" * 40}')
    print(f"  OVERALL: {'PASS' if overall else 'FAIL'}  ({passed_count}/{tested} tests, {skipped_count} skipped)")
    if failed_frames > 0:
        print(f"  Failed frames: {failed_frames}/{total_frames}")
    print(f'{"=" * 40}')
    sys.exit(0 if overall else 1)


if __name__ == '__main__':
    main()
