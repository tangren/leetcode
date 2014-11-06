#!/bin/sh
g++ reverse-integer.cpp -o reverse-integer.out -I../gtest/include ../gtest/lib/gtest-all.o ../gtest/lib/gtest_main.o  -lpthread -ldl&&./reverse-integer.out
