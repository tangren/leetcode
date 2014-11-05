/*
     Problem: longest-palindromic-substring
         Url: https://oj.leetcode.com/problems/longest-palindromic-substring/
 Description: 
*/

#include <iostream>
#include <gtest/gtest.h>

using namespace std;
using namespace testing;

struct PalStr {
    int start;
    int end;
    bool complete;
    PalStr() {
        start = -1;
        end = -1;
        complete = false;
    }

    PalStr(int s, int e) {
        start = s;
        end = e;
        complete = false;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) {
            return s;
        }
    
        vector<PalStr> subStrs;
        subStrs.reserve(1000);
        char pre = s[0];
        char prepre = '\0';
        for (int curPos = 1; curPos < s.length(); curPos++) {
            char cur = s[curPos];
            if (cur == pre) {
                subStrs.push_back(PalStr(curPos - 1, curPos));
            }
            
            if (cur == prepre) {
                subStrs.push_back(PalStr(curPos - 2, curPos));
            }
      
            prepre = pre;
            pre = cur;
            
            for (size_t i = 0; i < subStrs.size(); i++) {
                PalStr &p = subStrs[i];
                if (p.complete || curPos == p.end) {
                    continue;
                }
                
                if (p.start == 0) {
                    p.complete = true;
                    continue;
                } 
                
                if (cur == s[p.start - 1]) {
                    p.start = p.start - 1;
                    p.end = curPos;
                } else {
                    p.complete = true;
                }
            }
        }

        int maxLen = 0;
        int maxIdx = 0;
        for (size_t i = 0; i < subStrs.size(); i++) {
            const PalStr &p = subStrs[i];
            int len = p.end - p.start + 1;
            if (maxLen < len) {
                maxLen = len;
                maxIdx = i;
            }
        }

        return s.substr(subStrs[maxIdx].start, maxLen);
    }
};

TEST(SolutionTest, testSimple) {
    Solution s;
    ASSERT_EQ("a", s.longestPalindrome("a"));
    ASSERT_EQ("aa", s.longestPalindrome("aab"));
    ASSERT_EQ("aaa", s.longestPalindrome("aaa"));
    ASSERT_EQ("aba", s.longestPalindrome("abaa"));
    ASSERT_EQ("bcabacb", s.longestPalindrome("abcabacbcaa"));
    ASSERT_EQ("bcabbacb", s.longestPalindrome("abcabbacbcaa"));
    ASSERT_EQ("abbbbba", s.longestPalindrome("accabbbbba"));
    ASSERT_EQ("accabbbbbacca", s.longestPalindrome("accabbbbbacca"));
}

