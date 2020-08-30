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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode odd(0);
        ListNode even(0);
        ListNode *odd_iter = &odd;
        ListNode *even_iter = &even;
        int index = 1;
        while(head) {
            ListNode *tmp = head->next;
            // next = nullptr can let sublinklist node is clear. 
            head->next = nullptr;
            if(index&1) {
                odd_iter->next = head;
                odd_iter = odd_iter->next;
            } else {
                even_iter->next = head;
                even_iter = even_iter->next;
            }
            index++;
            head = tmp;
        }
        odd_iter->next = even.next;
        return odd.next;
    }
};

// Runtime: 8 ms, faster than 99.32% of C++ online submissions for Odd Even Linked List.
// Memory Usage: 9.7 MB, less than 76.28% of C++ online submissions for Odd Even Linked List.