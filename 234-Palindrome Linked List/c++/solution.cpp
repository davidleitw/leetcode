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
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        if(fast) slow = slow->next;
        ListNode *prev = nullptr;
        ListNode *next = nullptr;
        while(slow) {
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        
        
        // at this monent, slow is the reverse link list head;
        while (prev) {
            if (prev->val != head->val) return false;
            prev = prev->next;
            head = head->next;
        }
        return true;
    }
};

// Runtime: 24 ms, faster than 97.42% of C++ online submissions for Palindrome Linked List.
// Memory Usage: 14.2 MB, less than 66.41% of C++ online submissions for Palindrome Linked List.