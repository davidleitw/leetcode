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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr || root->val == val) return root;
        if(val > root->val) {
            return searchBST(root->right, val);
        } 
        
        return searchBST(root->left, val); 
    }
};

// Runtime: 36 ms, faster than 99.93% of C++ online submissions for Search in a Binary Search Tree.
// Memory Usage: 35.7 MB, less than 99.49% of C++ online submissions for Search in a Binary Search Tree.
