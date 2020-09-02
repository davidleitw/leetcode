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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode *solution = head->next;
        ListNode *prev = nullptr;
        ListNode *iter = head;
        while(iter) {
            if(iter->next) {
                ListNode *tmp = iter->next;
                iter->next = tmp->next;
                tmp->next = iter;
                if(prev) prev->next = tmp;
                prev = iter;
            }
            iter = iter->next;
        }
        return solution;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Swap Nodes in Pairs.
// Memory Usage: 7.5 MB, less than 66.57% of C++ online submissions for Swap Nodes in Pairs.