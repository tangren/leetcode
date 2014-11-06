/*
     Problem: regular-expression-matching
         Url: https://oj.leetcode.com/problems/regular-expression-matching/
 Description: Implement regular expression matching with support for '.' and '*'.

              '.' Matches any single character.
              '*' Matches zero or more of the preceding element.
              The function prototype should be:
              bool isMatch(const char *s, const char *p)

              Some examples:
              isMatch("aa","a") → false
              isMatch("aa","aa") → true
              isMatch("aaa","aa") → false
              isMatch("aa", "a*") → true
              isMatch("aa", ".*") → true
              isMatch("ab", ".*") → true
              isMatch("aab", "c*a*b") → true
 
*/

#include <iostream>
#include <gtest/gtest.h>

using namespace std;
using namespace testing;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {}
};

TEST(SolutionTest, testSimple) {
}

