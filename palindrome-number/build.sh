#!/bin/sh
g++ palindrome-number.cpp -o palindrome-number.out -I../gtest/include ../gtest/lib/gtest-all.o ../gtest/lib/gtest_main.o  -lpthread -ldl&&./palindrome-number.out
