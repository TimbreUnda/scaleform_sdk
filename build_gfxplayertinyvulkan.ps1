# Build GFxPlayerTinyVulkan (Vulkan_Release x64): expat (MT) -> Render_Vulkan -> GFxPlayerTinyVulkan.
# Run from scaleform_sdk root.

$ErrorActionPreference = "Stop"
$root = $PSScriptRoot
$vsDevCmd = "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat"
$sln = Join-Path $root "Projects\Win32\Msvc10\Samples\GFx 4.2 Demos.sln"
$expatProj = Join-Path $root "3rdParty\expat-2.1.0\gfx_projects\Win32\Msvc10\expat.vcxproj"

if (-not (Test-Path $vsDevCmd)) { Write-Error "VsDevCmd.bat not found: $vsDevCmd"; exit 1 }
if (-not (Test-Path $sln)) { Write-Error "Solution not found: $sln"; exit 1 }
if (-not (Test-Path $expatProj)) { Write-Error "expat project not found: $expatProj"; exit 1 }

# 1) Clean + rebuild expat (Release x64) with /MT so 3rdParty\expat-2.1.0\lib\x64\Msvc10\Release\expat.lib is correct
Write-Host "=== Building expat (Release x64) with static CRT ===" -ForegroundColor Cyan
$cmd = "call `"$vsDevCmd`" && cd /d `"$root`" && msbuild `"$expatProj`" /t:Clean /p:Configuration=Release /p:Platform=x64 /v:minimal && msbuild `"$expatProj`" /p:Configuration=Release /p:Platform=x64 /v:minimal"
& $env:comspec /c $cmd
if ($LASTEXITCODE -ne 0) { Write-Error "expat build failed"; exit $LASTEXITCODE }

# 2) Build Render_Vulkan first (solution project reference path may not resolve)
$renderVulkanProj = Join-Path $root "Projects\Win32\Msvc10\SDK\Render\Render_Vulkan.vcxproj"
if (-not (Test-Path $renderVulkanProj)) { Write-Error "Render_Vulkan project not found: $renderVulkanProj"; exit 1 }
Write-Host "=== Building Render_Vulkan (Vulkan_Release x64) ===" -ForegroundColor Cyan
$cmdVk = "call `"$vsDevCmd`" && cd /d `"$root`" && msbuild `"$renderVulkanProj`" /t:Build /p:Configuration=Vulkan_Release /p:Platform=x64 /v:minimal"
& $env:comspec /c $cmdVk
if ($LASTEXITCODE -ne 0) { Write-Error "Render_Vulkan build failed"; exit $LASTEXITCODE }

# 3) Build solution: GFxPlayerTinyVulkan (Vulkan_Release x64)
Write-Host "=== Building GFx 4.2 Demos (Vulkan_Release x64) ===" -ForegroundColor Cyan
$cmd2 = "call `"$vsDevCmd`" && cd /d `"$root`" && msbuild `"$sln`" /p:Configuration=Vulkan_Release /p:Platform=x64 /t:GFxPlayerTinyVulkan /v:minimal"
& $env:comspec /c $cmd2
exit $LASTEXITCODE
