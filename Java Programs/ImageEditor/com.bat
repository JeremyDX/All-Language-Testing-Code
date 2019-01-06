@echo off
title Compiling...
:com
echo Clearing out the bin folder..
SET PATH=D:\Java\jdk\bin
echo Compiling...
javac *.java
echo done.
pause
cls
goto com