@echo off
echo "Compiling..."
g++ main.cpp ../lib/**.cpp -o run
echo "Running..."
echo.
run.exe
