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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* topNode = q.front(); q.pop();
            if(s.find(k - topNode->val) != s.end()) return true;
            s.insert(topNode->val);
            
            if(topNode->left) q.push(topNode->left);
            if(topNode->right) q.push(topNode->right);
        }
        return false;
    }
};

// Runtime: 56 ms, faster than 68.20% of C++ online submissions for Two Sum IV - Input is a BST.
// Memory Usage: 38.6 MB, less than 7.32% of C++ online submissions for Two Sum IV - Input is a BST.
