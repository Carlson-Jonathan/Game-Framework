#!/bin/bash
clear
g++ -c main.cpp
g++ main.o -o executable.out -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
rm main.o
./executable.out
rm executable.out
exit