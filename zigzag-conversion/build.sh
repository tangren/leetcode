#!/bin/sh
g++ zigzag-conversion.cpp -o zigzag-conversion.out -I../gtest/include ../gtest/lib/gtest-all.o ../gtest/lib/gtest_main.o  -lpthread -ldl&&./zigzag-conversion.out
