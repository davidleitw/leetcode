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
    int rangeSumBST(TreeNode* root, int L, int R) {
        return solve(root, L, R);    
    }
    
    int solve(TreeNode* root, int L, int R) {
        if(root == nullptr) return 0;
        if(root->val >= L && root->val <= R) {
            return root->val + solve(root->left, L, R) + solve(root->right, L, R);
        }
        return solve(root->left, L, R) + solve(root->right, L, R);
    }
};

// Runtime: 164 ms, faster than 97.71% of C++ online submissions for Range Sum of BST.
// Memory Usage: 65.1 MB, less than 5.21% of C++ online submissions for Range Sum of BST.