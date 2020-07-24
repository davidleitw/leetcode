#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int solve = 0;
        while(head != NULL) {
            if(head->val == 1)
                solve |= head->val;

            head = head->next;
            if(head != NULL) 
                solve = solve << 1;
        }
        return solve;
    }
};

// 0 ms, faster than 100.00% of C++ online submissions for Convert Binary Number in a Linked List to Integer.
// 8.4 MB, less than 47.21% of C++ online submissions for Convert Binary Number in a Linked List to Integer.