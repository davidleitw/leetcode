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
    vector<vector<int>> v;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return v;
        queue<TreeNode*> q;
        
        q.push(root);
        while(!q.empty()) {
            vector<int> nums;
            int n = q.size();
            for(int i = 0; i < n; ++i) {
                TreeNode *tmp = q.front();
                q.pop();
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
                nums.push_back(tmp->val);
            }
            if(n != 0) v.push_back(nums);
        }
        
        return v;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Level Order Traversal.
// Memory Usage: 12.9 MB, less than 18.42% of C++ online submissions for Binary Tree Level Order Traversal.