#!/bin/bash
clear
g++ testHarness.cpp miscellaneous_test.cpp ../miscellaneous.cpp
./a.out
rm a.out
exit;