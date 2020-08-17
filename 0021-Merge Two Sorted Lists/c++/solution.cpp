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

// Recursive
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) 
            return l2;
        
        if(l2 == nullptr) 
            return l1;
        
        if(l1->val >= l2->val) {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        } 
        
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
};

// 4 ms, faster than 96.65% of C++ online submissions for Merge Two Sorted Lists. 
// 14.3 MB, less than 95.02% of C++ online submissions for Merge Two Sorted Lists.


// Iterative
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode temp(0);
        ListNode *tail = &temp;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            }else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        if(l1) tail->next = l1;
        if(l2) tail->next = l2;
        
        return temp.next;
    }
};