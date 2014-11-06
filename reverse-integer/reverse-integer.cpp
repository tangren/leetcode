/*
     Problem: reverse-integer
         Url: https://oj.leetcode.com/problems/reverse-integer/
 Description: Reverse digits of an integer.
              Example1: x = 123, return 321
              Example2: x = -123, return -321
*/

#include <iostream>
#include <gtest/gtest.h>

using namespace std;
using namespace testing;

class Solution {
public:
    int reverse(int x) {
        int sign = x >= 0 ? 1 : -1;
        int t = x >= 0 ? x : -x;
        int y = 0;
        while (t > 0) {
            y = y * 10 + t % 10;
            t = t / 10;
        }
        if (y & 0x80000000) {
            return 0;
        }
        return y * sign;
    }
};

TEST(SolutionTest, testSimple) {
    Solution s;
    ASSERT_EQ(321, s.reverse(123));
    ASSERT_EQ(-321, s.reverse(-123));
    ASSERT_EQ(1, s.reverse(100));
    ASSERT_EQ(0, s.reverse(0));
    ASSERT_EQ(0, s.reverse(numeric_limits<int>::max()));
    ASSERT_EQ(0, s.reverse(numeric_limits<int>::min()));
}

