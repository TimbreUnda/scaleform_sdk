# Build Render_Vulkan project. Run from scaleform_sdk root (this script's directory).
# Uses VS 2022 Developer environment via VsDevCmd.bat so MSBuild is on PATH.

$ErrorActionPreference = "Stop"
$root = $PSScriptRoot
$proj = Join-Path $root "Projects\Win32\Msvc10\SDK\Render\Render_Vulkan.vcxproj"
$vsDevCmd = "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat"

if (-not (Test-Path $proj)) {
    Write-Error "Project not found: $proj"
    exit 1
}
if (-not (Test-Path $vsDevCmd)) {
    Write-Error "VsDevCmd.bat not found: $vsDevCmd"
    exit 1
}

# Run build in a cmd that has run VsDevCmd.bat so msbuild is available
$cmd = "call `"$vsDevCmd`" && cd /d `"$root`" && msbuild `"$proj`" /p:Configuration=Vulkan_Release /p:Platform=Win32 /v:minimal"
& $env:comspec /c $cmd
exit $LASTEXITCODE
