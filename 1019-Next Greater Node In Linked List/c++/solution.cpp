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

// Find the first greater element. Monotonic stack
// leetcode 739, 901, 1019

class Solution {
public:
    Solution(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums;
        while(head) {
            nums.push_back(head->val);
            head = head->next;
        }

        stack<int> s;
        vector<int> solution(nums.size());
        for(int i = nums.size() - 1; i >= 0; --i) {
            while(!s.empty() && nums[i] >= s.top()) s.pop();
            solution[i] = s.empty() ? 0 : s.top();
            s.push(nums[i]);
        }

        return solution;
    }
};

// Runtime: 92 ms, faster than 99.70% of C++ online submissions for Next Greater Node In Linked List.
// Memory Usage: 42.4 MB, less than 47.36% of C++ online submissions for Next Greater Node In Linked List.
