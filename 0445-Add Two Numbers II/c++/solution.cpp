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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        while(l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int sum = 0;
        ListNode *solution = new ListNode(0);
        while(!s1.empty() || !s2.empty()) {
            if(!s1.empty()) {
                sum += s1.top(); 
                s1.pop();
            } 
            if(!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }
            solution->val = sum % 10;
            ListNode *insert = new ListNode(sum/10);
            insert->next = solution;
            solution = insert;
            sum = sum / 10;
        }
        if(solution->val == 0) return solution->next; // 最後一次運算沒有進位的情況
        return solution;
    }
    
};

// Runtime: 20 ms, faster than 99.02% of C++ online submissions for Add Two Numbers II.
// Memory Usage: 72.8 MB, less than 20.09% of C++ online submissions for Add Two Numbers II.