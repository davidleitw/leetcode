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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *solution;
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while(cur) {
            pair<ListNode*, ListNode*> p =  travel(cur, k);
            if(p.first) {
                ListNode *curNext = reverse(p.first, p.second);
                if(!pre) {
                    solution = p.second;
                } else {
                    pre->next = p.second;
                }
                pre = p.first;
                cur = curNext;
            } else {
                break;
            }
        }
        
        return solution;
    }
    /*
        return a group of nodes' head and tail.
    */
    pair<ListNode*, ListNode*> travel(ListNode *head, int k) {
        ListNode *curr = head;
        for(int i = 1; i < k; ++i) {
            curr = curr->next;
            if(!curr) {
                break;   
            }
        }
        if(!curr) return {nullptr, nullptr};
        return {head, curr};
    }
    
    ListNode* reverse(ListNode *head, ListNode *tail) {
        ListNode *pre = tail->next;
        ListNode *cur = head;
        tail->next = nullptr;
        while(cur) {
            ListNode *curNext = cur->next;
            cur->next = pre;
            pre = cur;
            cur = curNext;
        }
        return head->next;
    }   
};
