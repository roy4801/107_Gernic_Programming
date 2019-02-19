@echo off

set COMPILER=-std=c++11
set CFLAGS=
set LIBS=

echo Compiling...
g++ %COMPILER% %1.cpp -o %1.exe
if %ERRORLEVEL% EQU 0 (
	echo Complete.
)