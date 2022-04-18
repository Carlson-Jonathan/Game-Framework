#!/bin/bash
#This script was being used early on, but I switched to cmake and now it probably doesnt work.
clear
g++ -c main.cpp miscellaneous.cpp
g++ main.o -o executable.out -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
./executable.out
rm main.o
exit