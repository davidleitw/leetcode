#include <bits/stdc++.h>
using namespace std;

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return nullptr;
        return helper(nums, 0, nums.size()-1);
    }
    
    TreeNode* helper(vector<int>& nums, int start_index, int end_index) {
        if(start_index > end_index) return nullptr;
        int middle_index = (start_index + end_index)/2;
        TreeNode *middle = new TreeNode(nums[middle_index]);
        middle->left = helper(nums, start_index, middle_index-1);
        middle->right = helper(nums, middle_index+1, end_index);
        return middle;
    }
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return nullptr;
        int middle_index = nums.size()/2;
        auto begin_iter = nums.begin();
        TreeNode *middle = new TreeNode(nums[middle_index]);
        vector<int> left(begin_iter, begin_iter+middle_index);
        vector<int> right(begin_iter+middle_index+1, nums.end());
        middle->left = sortedArrayToBST(left);
        middle->right = sortedArrayToBST(right);
        return middle;
    }
};

// Runtime: 28 ms, faster than 34.62% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
// Memory Usage: 25.9 MB, less than 15.19% of C++ online submissions for Convert Sorted Array to Binary Search Tree.