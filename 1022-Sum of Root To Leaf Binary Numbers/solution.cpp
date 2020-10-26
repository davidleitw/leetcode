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
    int sumRootToLeaf(TreeNode* root) {
        return solve(root, 0);
    }
    int solve(TreeNode *root, int val) {
        if(!root) return 0;
        val = (val << 1) + root->val;
        if(!root->left && !root->right) return val;
        return solve(root->left, val) + solve(root->right, val);
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sum of Root To Leaf Binary Numbers.
// Memory Usage: 17.2 MB, less than 5.61% of C++ online submissions for Sum of Root To Leaf Binary Numbers.