/*
     Problem: zigzag-conversion
         Url: https://oj.leetcode.com/problems/zigzag-conversion/
 Description: 
*/

#include <iostream>
#include <gtest/gtest.h>

using namespace std;
using namespace testing;

class Solution {
public:
  string convert(string text, int nRows) {
      if (nRows <= 1) {
          return text;
      }
      
      string outText;
      int span = 2 * nRows - 2;
      for (int row = 0; row < nRows; row++) {
          int pos = row;
          int colMax = text.length() / span + 1;
          colMax = row == 0 || row == nRows - 1 ? colMax : colMax * 2;
          for (int col = 0; col < colMax && pos < text.length(); col++) {
              outText += text[pos];
              int subSpan = col % 2 == 0 ? span - 2 * row : 2 * row;
              pos += (subSpan == 0 ? span : subSpan);
          }
      }
      return outText;
  }
};

TEST(SolutionTest, testSimple) {
    Solution s;
    ASSERT_EQ("PAHNAPLSIIGYIR", s.convert("PAYPALISHIRING", 3));
    ASSERT_EQ("PYAIHRNAPLSIIG", s.convert("PAYPALISHIRING", 2));
    ASSERT_EQ("A", s.convert("A", 2));
    ASSERT_EQ("AB", s.convert("AB", 2));
    ASSERT_EQ("ABC", s.convert("ABC", 3));
    ASSERT_EQ("ABCD", s.convert("ABCD", 4));
}

