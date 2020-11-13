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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode *t = q.front(); q.pop();
            if(t->left) {
                t->left->val += t->val;
                q.push(t->left);
            } 
            if(t->right) {
                t->right->val += t->val;
                q.push(t->right);
            }
            if(!t->left && !t->right) {
                if(t->val == sum) return true;   
            }
        }
        return false;
    }
};

// Runtime: 8 ms, faster than 98.40% of C++ online submissions for Path Sum.
// Memory Usage: 22.1 MB, less than 59.49% of C++ online submissions for Path Sum.

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        return solve(root, 0, sum);
    }
    
    bool solve(TreeNode *root, int s, int sum) {
        if(!root) return false;
        if(!root->left && !root->right) {
            if(s + root->val == sum) return true; 
        }
        return solve(root->left, s + root->val, sum) || solve(root->right, s + root->val, sum);
    }
};

// Runtime: 4 ms, faster than 99.95% of C++ online submissions for Path Sum.
// Memory Usage: 21.8 MB, less than 59.49% of C++ online submissions for Path Sum.

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return solve(root, 0, sum);
    }
    
    bool solve(TreeNode *root, int s, int sum) {
        if(!root) return false;
        s += root->val;
        if(!root->left && !root->right && s == sum) return true; 
        return solve(root->left, s, sum) || solve(root->right, s, sum);
    }
};