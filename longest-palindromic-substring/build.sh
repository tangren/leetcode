#!/bin/sh
g++ longest-palindromic-substring.cpp -o longest-palindromic-substring.out -I../gtest/include ../gtest/lib/gtest-all.o ../gtest/lib/gtest_main.o  -lpthread -ldl&&./longest-palindromic-substring.out
