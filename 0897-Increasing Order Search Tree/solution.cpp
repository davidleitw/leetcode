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
    TreeNode* increasingBST(TreeNode *root) { 
        TreeNode solution(0);
        iterator = &solution;
        Inorder(root);
        return solution.right;
    }
private:
    TreeNode *iterator;
    void Inorder(TreeNode *root) {
        if(!root) return;
        Inorder(root->left);
        iterator->right = root;
        iterator = iterator->right;
        iterator->left = nullptr;
        Inorder(root->right);
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Increasing Order Search Tree.
// Memory Usage: 7.9 MB, less than 14.65% of C++ online submissions for Increasing Order Search Tree.