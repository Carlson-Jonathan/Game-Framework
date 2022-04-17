#!/bin/bash
clear
g++ -c main.cpp
g++ main.o -o executable.out -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
./executable.out
rm main.o
exit