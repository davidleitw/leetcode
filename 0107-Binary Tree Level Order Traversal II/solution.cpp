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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        
        vector<vector<int>> solution;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            const int levelNum = q.size();
            vector<int> levelVal;
            for(int i = 0; i < levelNum; ++i) {
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                levelVal.push_back(q.front()->val);
                q.pop();
            }
            solution.push_back(levelVal);
        }
        reverse(solution.begin(), solution.end());
        return solution;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Level Order Traversal II.
// Memory Usage: 12.8 MB, less than 20.70% of C++ online submissions for Binary Tree Level Order Traversal II.