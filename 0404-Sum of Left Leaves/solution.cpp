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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        int sum = sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        if(root->left && !root->left->left && !root->left->right) sum += root->left->val;
        return sum;
    }
    
};

// Runtime: 4 ms, faster than 83.77% of C++ online submissions for Sum of Left Leaves.
// Memory Usage: 13.8 MB, less than 83.21% of C++ online submissions for Sum of Left Leaves.