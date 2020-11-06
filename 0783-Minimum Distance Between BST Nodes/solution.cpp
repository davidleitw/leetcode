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
    vector<int> nums;
    int minDiffInBST(TreeNode* root) {
        if(!root) return 0;
        Inorder(root);
        int solution = INT_MAX;
        for(int i = 1; i < nums.size(); ++i) {
            if(solution > abs(nums[i] - nums[i - 1])) {
                solution = abs(nums[i] - nums[i - 1]);
            }
        }
        return solution;
    }
    void Inorder(TreeNode *root) {
        if(!root) return;
        Inorder(root->left);
        nums.push_back(root->val);
        Inorder(root->right);
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Distance Between BST Nodes.
// Memory Usage: 10.8 MB, less than 10.74% of C++ online submissions for Minimum Distance Between BST Nodes.
