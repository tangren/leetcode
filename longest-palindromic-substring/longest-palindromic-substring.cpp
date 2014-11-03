/*
     Problem: longest-palindromic-substring
         Url: https://oj.leetcode.com/problems/longest-palindromic-substring/
 Description: 
*/

#include <iostream>
#include <gtest/gtest.h>

using namespace std;
using namespace testing;

struct Pos {
  int start;
  int end;
  bool complete;
  Pos() {
    start = -1;
    end = -1;
    complete = false;
  }
};

class Solution {
public:
  string longestPalindrome(string s) {
    cout << "***** string:" << s << endl;
    if (s.length() <= 1) {
      return s;
    }
    
    vector<Pos> subStrs;
    subStrs.reserve(1000);
    char pre = s[0];
    char prepre;
    for (int curPos = 1; curPos < s.length(); curPos++) {
      char cur = s[curPos];
      if (cur == pre) {
	Pos p;
	p.start = curPos;
	p.end = curPos;
	subStrs.push_back(p);
	
	if (curPos > 1) {
	  prepre = s[curPos - 2];
	  if (cur == prepre) {
	    Pos p;
	    p.start = curPos - 1;
	    p.end = curPos;
	    subStrs.push_back(p);
	  }
	}
      } else {
	if (curPos > 1) {
	  prepre = s[curPos - 2];
	  if (cur == prepre) {
	    Pos p;
	    p.start = curPos - 1;
	    p.end = curPos;
	    subStrs.push_back(p);
	  }
	}
      }

      prepre = pre;
      pre = cur;
      
      for (size_t i = 0; i < subStrs.size(); i++) {
	Pos &p = subStrs[i];
	if (p.complete) {
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

	cout << "cur:" << cur
	     << ", curPos:" << curPos
	     << ", start:" << subStrs[i].start 
	     << ", end:" << subStrs[i].end << ", "
	     << s.substr(subStrs[i].start, 
			 subStrs[i].end - subStrs[i].start + 1) 
	     << ", complete:" << subStrs[i].complete << endl;
      }
    }

    int maxLen = 0;
    int maxIdx = 0;
    for (size_t i = 0; i < subStrs.size(); i++) {
      const Pos &p = subStrs[i];
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

