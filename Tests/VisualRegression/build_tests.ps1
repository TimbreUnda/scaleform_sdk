# Build visual regression test tools: CaptureD3D11 and CaptureVulkan.
# Run from scaleform_sdk root, or from Tests/VisualRegression.

$ErrorActionPreference = "Stop"

# Locate scaleform_sdk root (two levels up from this script if run in-place)
$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$root = (Resolve-Path (Join-Path $scriptDir "..\..")).Path

$vsDevCmd = "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat"
if (-not (Test-Path $vsDevCmd)) {
    # Try Community 2019
    $vsDevCmd = "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\Tools\VsDevCmd.bat"
}
if (-not (Test-Path $vsDevCmd)) {
    Write-Error "VsDevCmd.bat not found. Please set the path for your Visual Studio installation."
    exit 1
}

$expatProj        = Join-Path $root "3rdParty\expat-2.1.0\gfx_projects\Win32\Msvc10\expat.vcxproj"
$renderVkProj     = Join-Path $root "Projects\Win32\Msvc10\SDK\Render\Render_Vulkan.vcxproj"
$captureD3D11Proj = Join-Path $root "Projects\Win32\Msvc10\Tests\CaptureD3D11\CaptureD3D11.vcxproj"
$captureVkProj    = Join-Path $root "Projects\Win32\Msvc10\Tests\CaptureVulkan\CaptureVulkan.vcxproj"

foreach ($proj in @($expatProj, $renderVkProj, $captureD3D11Proj, $captureVkProj)) {
    if (-not (Test-Path $proj)) { Write-Error "Project not found: $proj"; exit 1 }
}

function MSBuild([string]$proj, [string]$config, [string]$platform, [string]$target = "Build") {
    # Use '&' (not '&&') after VsDevCmd.bat so its non-zero exit (vswhere not found)
    # does not abort the build; cmd.exe exits with msbuild's own exit code.
    $cmd = "call `"$vsDevCmd`" 2>nul & cd /d `"$root`" && msbuild `"$proj`" /t:$target /p:Configuration=$config /p:Platform=$platform /p:PlatformToolset=v143 /v:minimal /m"
    & $env:comspec /c $cmd
    if ($LASTEXITCODE -ne 0) { Write-Error "MSBuild failed for $(Split-Path -Leaf $proj) ($config|$platform)"; exit $LASTEXITCODE }
}

# 1) Build expat (Release x64, static CRT)
Write-Host "=== Building expat (Release x64) ===" -ForegroundColor Cyan
MSBuild $expatProj "Release" "x64" "Clean"
MSBuild $expatProj "Release" "x64"

# 2) Build Render_Vulkan lib
Write-Host "=== Building Render_Vulkan (Vulkan_Release x64) ===" -ForegroundColor Cyan
MSBuild $renderVkProj "Vulkan_Release" "x64"

# 3) Build CaptureD3D11
Write-Host "=== Building CaptureD3D11 (D3D11_Release x64) ===" -ForegroundColor Cyan
MSBuild $captureD3D11Proj "D3D11_Release" "x64"

# 4) Build CaptureVulkan
Write-Host "=== Building CaptureVulkan (Vulkan_Release x64) ===" -ForegroundColor Cyan
MSBuild $captureVkProj "Vulkan_Release" "x64"

Write-Host ""
Write-Host "Build complete. Binaries in: $root\Bin\x64\Msvc10\Tests\" -ForegroundColor Green
