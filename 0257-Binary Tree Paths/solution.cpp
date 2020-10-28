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
    vector<string> solution;
    vector<string> binaryTreePaths(TreeNode* root) {
        solve(root, "");
        return solution;
    }
    void solve(TreeNode *root, string path) {
        if(!root) return;
        if(!root->left && !root->right) solution.push_back(path + to_string(root->val));
        path += to_string(root->val) + "->";
        solve(root->left, path);
        solve(root->right, path);
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Paths.
// Memory Usage: 14.1 MB, less than 13.38% of C++ online submissions for Binary Tree Paths.