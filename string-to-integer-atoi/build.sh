#!/bin/sh
g++ string-to-integer-atoi.cpp -o string-to-integer-atoi.out -I../gtest/include ../gtest/lib/gtest-all.o ../gtest/lib/gtest_main.o  -lpthread -ldl&&./string-to-integer-atoi.out
