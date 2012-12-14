@echo off
if "%1" == "" goto x86
if not "%2" == "" goto usage

cd /D "%ProgramFiles(x86)%\Microsoft Visual Studio 11.0\VC"
call "%ProgramFiles(x86)%\Microsoft Visual Studio 11.0\VC\vcvarsall.bat" %1

set INCLUDE=%ProgramFiles(x86)%\Microsoft SDKs\Windows\7.1A\Include;%INCLUDE%
set PATH=%ProgramFiles(x86)%\Microsoft SDKs\Windows\7.1A\Bin;%PATH%
set CL=/D_USING_V110_SDK71_;%CL%

if /i %1 == x86       goto x86
if /i %1 == x86_amd64 goto x86_amd64
goto usage

:x86
set LIB=%ProgramFiles(x86)%\Microsoft SDKs\Windows\7.1A\Lib;%LIB%
goto :eof

:x86_amd64
set LIB=%ProgramFiles(x86)%\Microsoft SDKs\Windows\7.1A\Lib\x64;%LIB%
goto :eof


:usage
echo Error in script usage. The correct usage is:
echo     %0 [option]
echo where [option] is: x86 ^| x86_amd64
echo:
echo For example:
echo     %0 x86_amd64
goto :eof