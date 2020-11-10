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
    vector<double> solution;
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            long long int sum = 0;
            int num = q.size();
            for(int i = 0; i < num; ++i) {
                TreeNode *tmp = q.front();
                q.pop();
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
                sum += tmp->val;
            }
            if(num != 0) solution.push_back((double)sum / num);
        }
        return solution;
    }
};

// Runtime: 12 ms, faster than 99.44% of C++ online submissions for Average of Levels in Binary Tree.
// Memory Usage: 23.1 MB, less than 5.03% of C++ online submissions for Average of Levels in Binary Tree.