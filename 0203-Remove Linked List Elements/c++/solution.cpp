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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return nullptr;
        while(head != nullptr && head->val == val) head = head->next;
        
        ListNode *prev = nullptr;
        ListNode *start = head;
        while(start) {
            if(start->val == val) {
                // do something to delete node;
                prev->next = start->next;
                start = start->next;
                continue;
            }
            prev = start;
            start = start->next;
        }
        return head;
    }
};

// Runtime: 16 ms, faster than 99.87% of C++ online submissions for Remove Linked List Elements.
// Memory Usage: 13.5 MB, less than 74.39% of C++ online submissions for Remove Linked List Elements.