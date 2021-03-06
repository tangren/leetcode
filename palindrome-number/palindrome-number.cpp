/*
     Problem: palindrome-number
         Url: https://oj.leetcode.com/problems/palindrome-number/
 Description: Determine whether an integer is a palindrome. Do this without extra space.
*/

#include <iostream>
#include <gtest/gtest.h>

using namespace std;
using namespace testing;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int y = 0;
        int l = x;
        do {
            if (y > 0) {
                if (y > numeric_limits<int>::max() / 10 ||
                    numeric_limits<int>::max() - y * 10 < l % 10)
                {
                    return false;
                }
            }
            y = y * 10 + l % 10;
            l = l / 10;
        } while (l > 0);
        return y == x;
    }
};

TEST(SolutionTest, testSimple) {
    Solution s;

    ASSERT_TRUE(s.isPalindrome(1));
    ASSERT_FALSE(s.isPalindrome(-1));
    ASSERT_FALSE(s.isPalindrome(-1111));
    ASSERT_TRUE(s.isPalindrome(11));
    ASSERT_TRUE(s.isPalindrome(121));
    ASSERT_TRUE(s.isPalindrome(12321));
    ASSERT_TRUE(s.isPalindrome(1221));
    ASSERT_FALSE(s.isPalindrome(12));
    ASSERT_FALSE(s.isPalindrome(1231));
    ASSERT_FALSE(s.isPalindrome(12311));
    ASSERT_FALSE(s.isPalindrome(100));
    ASSERT_FALSE(s.isPalindrome(-2147447412));
}

