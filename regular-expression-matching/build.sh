#!/bin/sh
g++ regular-expression-matching.cpp -o regular-expression-matching.out -I../gtest/include ../gtest/lib/gtest-all.o ../gtest/lib/gtest_main.o  -lpthread -ldl&&./regular-expression-matching.out
