#!/bin/sh
g++ add-two-numbers.cpp -o add-two-numbers.out -I/Users/zhouhb/Work/git/leetcode/add-two-numbers/../gtest/include ../gtest/lib/gtest-all.o ../gtest/lib/gtest_main.o  -lpthread -ldl&&./add-two-numbers.out
