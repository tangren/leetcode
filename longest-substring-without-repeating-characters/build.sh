#!/bin/sh
g++ longest-substring-without-repeating-characters.cpp -o longest-substring-without-repeating-characters.out -I../gtest/include ../gtest/lib/gtest-all.o ../gtest/lib/gtest_main.o  -lpthread -ldl&&./longest-substring-without-repeating-characters.out
