/*
     Problem: add-two-numbers
         Url: https://oj.leetcode.com/problems/add-two-numbers/
 Description: 
*/

#include <iostream>
#include <gtest/gtest.h>

using namespace std;
using namespace testing;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int v) : val(v), next(NULL) {}
};
    
class Solution {
public:
    void sum(int v1, int v2, int &v, int &carry) {
        v = v1 + v2 + carry;
        if (v >= 10) {
            v = v - 10;
            carry = 1;
        } else {
            carry = 0;
        }
    }

    void addNode(ListNode **node, int v) {
        if ((*node) == NULL) {
            *node = new ListNode(v);
        } else {
            (*node)->next = new ListNode(v);
        }
    }
    
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int carry = 0;
        ListNode *result = NULL;
        ListNode **node = &result;
        while (l1 != NULL || l2 != NULL) {
            int v1 = l1 != NULL ? l1->val : 0;
            int v2 = l2 != NULL ? l2->val : 0;
            int v = 0;
            sum(v1, v2, v, carry);
            addNode(node, v);
            node = &((*node)->next);
            l1 = l1 != NULL ? l1->next : NULL;
            l2 = l2 != NULL ? l2->next : NULL;
        }

        if (carry) {
            addNode(node, carry);
        }
        
        return result;
    }
};

ListNode* n2l(long v) {
    ListNode *result = NULL;
    ListNode **node = &result;
    int l = v;
    int r = 0;
    do {
        r = l % 10;
        l = l / 10;

        if (*node == NULL) {
            *node = new ListNode(r);
        } else {
            (*node)->next = new ListNode(r);
            node = &((*node)->next);
        }
    } while (l > 0);
    return result;
}

long l2n(ListNode *l) {
    long v = 0;
    long base = 1;
    while (l) {
        v = v + l->val * base;
        l = l->next;
        base *= 10;
    }
    return v;
}

TEST(SolutionTest, testSimple) {
    Solution s;
    
    ListNode *l1 = n2l(1);
    ListNode *l2 = n2l(1);
    ASSERT_EQ(2, l2n(s.addTwoNumbers(l1, l2)));
    ASSERT_EQ(10, l2n(s.addTwoNumbers(n2l(5), n2l(5))));
    ASSERT_EQ(10, l2n(s.addTwoNumbers(n2l(0), n2l(10))));
    ASSERT_EQ(11, l2n(s.addTwoNumbers(n2l(9), n2l(2))));
    ASSERT_EQ(21, l2n(s.addTwoNumbers(n2l(11), n2l(10))));
    ASSERT_EQ(21, l2n(s.addTwoNumbers(n2l(12), n2l(9))));
    ASSERT_EQ(200, l2n(s.addTwoNumbers(n2l(192), n2l(8))));
}

