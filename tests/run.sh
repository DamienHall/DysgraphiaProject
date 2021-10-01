#!/bin/sh
clear
echo "Compiling..."
g++ main.cpp ../lib/**.cpp -o run.out
echo "Running...\n"
./run.out
#Linux, Compile and Run
