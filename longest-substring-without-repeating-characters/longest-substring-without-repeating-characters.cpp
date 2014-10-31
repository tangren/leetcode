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
        int maxLen = 0;
        vector<int> posIdx(256, -1);
        int curLen = 0;
        int startPos = 0;
        for (int pos = 0; pos < (int)s.length(); pos++) {
            const char &c = s[pos];
            if (posIdx[c] >= startPos) {
                maxLen = maxLen > curLen ? maxLen : curLen;
                curLen -= (posIdx[c] - startPos);
                startPos = posIdx[c] + 1;
                posIdx[c] = pos;
            } else {
                curLen++;
                posIdx[c] = pos;
            }
        }
        
        return maxLen > curLen ? maxLen : curLen;
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
    ASSERT_EQ(12, s.lengthOfLongestSubstring("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco"));
    ASSERT_EQ(12, s.lengthOfLongestSubstring("hnwnkuewhsqmgbbuqcljjivswmdkqtbxixmvtrrbljptnsnfwzqfjmafadrrwsofsbcnuvqhffbsaqxwpqcac"));
}
