/*
     Problem: string-to-integer-atoi
         Url: https://oj.leetcode.com/problems/string-to-integer-atoi/
 Description: 
*/

#include <iostream>
#include <gtest/gtest.h>

using namespace std;
using namespace testing;

class Solution {
public:
    int atoi(const char *str) {
        if (str == NULL) {
            return 0;
        }

        const char *s = str;
        if (*s == '\0') {
            return 0;
        }

        while (*s != '\0' && (*s == ' ' || *s == '\t')) {
            s++;
        }

        int sign = 1;
        int x = 0;
        
        if (*s == '-') {
            sign = -1;
            s++;
        } else if (*s == '+') {
            sign = 1;
            s++;
        }

        while (*s != '\0') {
            if (*s >= '0' && *s <= '9') {
                int v = *s - '0';
                if (x != 0) {
                    if (sign == 1) {
                        if (x > numeric_limits<int>::max() / 10 ||
                                numeric_limits<int>::max() - x * 10 < v)
                        {
                            return numeric_limits<int>::max();
                        }
                    } else if (sign == -1) {
                        if (x < numeric_limits<int>::min() / 10 ||
                                x * 10 - numeric_limits<int>::min() < v )
                        {
                            return  numeric_limits<int>::min();
                        }
                    }
                }

                x = x * 10 + sign * v;
                s++;
                continue;
            }

            break;
        }
        return x;
    }
};

TEST(SolutionTest, testSimple) {
    Solution s;
    ASSERT_EQ(0, s.atoi(""));
    ASSERT_EQ(0, s.atoi(NULL));
    ASSERT_EQ(0, s.atoi("a"));
    ASSERT_EQ(0, s.atoi(" "));
    ASSERT_EQ(0, s.atoi(" \t"));
    ASSERT_EQ(0, s.atoi(" \ta"));
    ASSERT_EQ(0, s.atoi(" \t0"));
    ASSERT_EQ(0, s.atoi(" \t0 \t"));
    ASSERT_EQ(0, s.atoi("-0"));
    ASSERT_EQ(1, s.atoi("1"));
    ASSERT_EQ(-1, s.atoi("-1"));
    ASSERT_EQ(-1, s.atoi(" \t -1 \t"));
    ASSERT_EQ(-123456, s.atoi("-123456"));
    ASSERT_EQ(-123456, s.atoi(" \t -123456 \t"));
    ASSERT_EQ(0, s.atoi("--123456"));
    ASSERT_EQ(-123, s.atoi("-123 456"));
    ASSERT_EQ(-123, s.atoi("-123a456"));
    ASSERT_EQ(123456, s.atoi("123456"));
    ASSERT_EQ(123456, s.atoi("+123456"));
    ASSERT_EQ(-12, s.atoi("  -0012a42"));
    ASSERT_EQ(123, s.atoi("123 456"));
    ASSERT_EQ(2147483647, s.atoi("    10522545459"));
    ASSERT_EQ(-2147483647, s.atoi("-2147483647"));
    ASSERT_EQ(-2147483648, s.atoi("-2147483648"));
    ASSERT_EQ(-2147483648, s.atoi("-2147483649"));
    ASSERT_EQ(2147483647, s.atoi("2147483647"));
    ASSERT_EQ(2147483647, s.atoi("2147483648"));
}

