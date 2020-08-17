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
    ListNode* middleNode(ListNode* head) {
        int num = 0;
        ListNode* solve = head;
        while(head != NULL) {
            head = head->next;
            num++;
            if(num %2 == 0) 
                solve = solve->next;
        }
        return solve;
    }
};

// 0 ms, faster than 100.00% of C++ online submissions for Middle of the Linked List.
// 6.8 MB, less than 19.67% of C++ online submissions for Middle of the Linked List.