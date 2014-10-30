/*
     Problem: longest-substring-without-repeating-characters
         Url: https://oj.leetcode.com/problems/longest-substring-without-repeating-characters/
 Description: 
*/

#include <iostream>
#include <gtest/gtest.h>

using namespace std;
using namespace testing;

class Solution {
public:
    int lengthOfLongestSubstring(const string &s) {
        size_t maxLen = 0;
        size_t startPos = 0;
        while (startPos < s.length()) {
            size_t len = findSubstring(s, startPos);
            maxLen = maxLen > len ? maxLen : len;
            startPos += len;
        }
        return maxLen;
    }

    size_t findSubstring(const string &s, size_t startPos) {
        char flags[128];
        memset(flags, 0, sizeof(flags));
        size_t len = 0;
        for (size_t i = startPos; i < s.length(); i++) {
            const char& c = s[i];
            if (flags[c] == 1) {
                break;
            } else {
                flags[c] = 1;
                len++;
            }
        }
        return len;
    }
};

TEST(SolutionTest, testSimple) {
    Solution s;

    ASSERT_EQ(0, s.lengthOfLongestSubstring(""));
    ASSERT_EQ(1, s.lengthOfLongestSubstring("a"));
    ASSERT_EQ(1, s.lengthOfLongestSubstring("aa"));
    ASSERT_EQ(2, s.lengthOfLongestSubstring("ab"));
    ASSERT_EQ(2, s.lengthOfLongestSubstring("aaba"));
    ASSERT_EQ(2, s.lengthOfLongestSubstring("aabaa"));
    ASSERT_EQ(2, s.lengthOfLongestSubstring("aabaaa"));
    ASSERT_EQ(3, s.lengthOfLongestSubstring("abcabcbb"));
    ASSERT_EQ(1, s.lengthOfLongestSubstring("bbbbbbb"));
    ASSERT_EQ(6, s.lengthOfLongestSubstring("abcdef"));
}
