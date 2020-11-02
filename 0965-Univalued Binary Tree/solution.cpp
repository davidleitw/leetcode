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
    set<int> s;
    bool isUnivalTree(TreeNode* root) {
        Inorder(root);
        if(s.size() != 1) return false;
        return true;
    }
    void Inorder(TreeNode *root) {
        if(!root) return;
        Inorder(root->left);
        s.insert(root->val);
        Inorder(root->right);
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Univalued Binary Tree.
// Memory Usage: 10.5 MB, less than 100.00% of C++ online submissions for Univalued Binary Tree.

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        return solve(root, root->val);
    }
    bool solve(TreeNode *root, int val) {
        if(!root) return true;
        if(root->val == val && solve(root->left, val) && solve(root->right, val)) return true;
        return false;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Univalued Binary Tree.
// Memory Usage: 10.2 MB, less than 100.00% of C++ online submissions for Univalued Binary Tree.