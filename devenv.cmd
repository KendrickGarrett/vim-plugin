@echo off

IF "" NEQ "%DEVENV%" (
	echo.The Dev environment has already been initialized
	exit /b 0
)

set DEVENV=%userprofile%\development

if "" NEQ "%1" (
	subst %~1 %DEVENV% > nul
	%1
)

if "" EQU "%1" (
	cd %DEVENV%
)

set path=%path%;%DEVENV%\vim\bin\
call vim

set path=%path%;%DEVENV%\bin\
set path=%path%;%programfiles(x86)%\Microsoft Visual Studio 14.0\vc\bin
path=%path%;%programfiles(x86)%\Windows Kits\10\bin\x86


::Set vim paths
set HOME=%DEVENV%\vim
set VIMRUNTIME=%HOME%\runtime
set VIM=%HOME%\bin
set VIMRC=%HOME%\_vimrc

set vsversion=14.0
set wkversion=10.0.10240.0

::Set the path for Visual binaries (cl, ml, etc.)
set VC_HOME=%ProgramFiles(x86)%\Microsoft Visual Studio %vsversion%\VC

::Set the path for win tools (guidgen, vsvars32, etc.)
path=%path%;%programfiles(x86)%\Microsoft Visual Studio %vsversion%\Common7\Tools

set PATH=%VC_HOME%\bin;%path%

set INCLUDE=%VC_HOME%\include;%INCLUDE%
set INCLUDE=%VC_HOME%\atlmfc\include;%INCLUDE%
set INCLUDE=%ProgramFiles(x86)%\Windows Kits\10\Include\%wkversion%\shared;%INCLUDE%
set INCLUDE=%ProgramFiles(x86)%\Windows Kits\10\Include\%wkversion%\ucrt;%INCLUDE%
set INCLUDE=%ProgramFiles(x86)%\Windows Kits\10\Include\%wkversion%\um;%INCLUDE%
set INCLUDE=%ProgramFiles(x86)%\Windows Kits\10\Include\%wkversion%\winrt;%INCLUDE%

::set INCLUCE=%ProgramFiles%\Microsoft SDKs\Windows\v7.0\Include;%INCLUDE%
::set INCLUDE=%ProgramFiles(x86)%\Microsoft SDKs\Windows\v7.1A\Include;%INCLUDE%

set LIB=%VC_HOME%\lib;%LIB%
set LIB=%VC_HOME%\atlmfc\lib;%LIB%
set LIB=%ProgramFiles(x86)%\Windows Kits\10\Lib\%wkversion%\ucrt\x86;%LIB%
set LIB=%ProgramFiles(x86)%\Windows Kits\10\Lib\%wkversion%\um\x86;%LIB%
::set LIB=%ProgramFiles(x86)%\Microsoft SDKs\Windows\v7.1A\Lib;%LIB%
