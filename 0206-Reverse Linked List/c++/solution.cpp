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
    ListNode* reverseList(ListNode* head) {
        ListNode *solve = NULL;
        while(head) {
            ListNode *tmp = head->next;
            head->next = solve;
            solve = head;
            head = tmp;
        }
        return solve;
    }
};

// 4 ms, faster than 96.72% of C++ online submissions for Reverse Linked List.
// 7.9 MB, less than 77.33% of C++ online submissions for Reverse Linked List.