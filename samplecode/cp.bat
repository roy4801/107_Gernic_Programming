@echo off

set COMPILER=-std=c++11
set CFLAGS=
set LIBS=

pushd %1
echo Compiling...

g++ %COMPILER% main.cpp -o main.exe

if %ERRORLEVEL% EQU 0 (
	echo Complete.
	main.exe
)

popd %1