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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next) {
            return new TreeNode(head->val);
        }
        
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *last = head;
        while(fast->next && fast->next->next) {
            last = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        last->next = nullptr;
        
        TreeNode *middle = new TreeNode(slow->val);  
        if(head != slow)
            middle->left = sortedListToBST(head);
        middle->right = sortedListToBST(fast);
        return middle;
    }
};

// Runtime: 32 ms, faster than 54.02% of C++ online submissions for Convert Sorted List to Binary Search Tree.
// Memory Usage: 31.3 MB, less than 21.86% of C++ online submissions for Convert Sorted List to Binary Search Tree.