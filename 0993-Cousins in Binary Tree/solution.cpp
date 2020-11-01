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
    struct Node{
        int depth;
        int parent_val;
        TreeNode *node;
    };
    
    bool isCousins(TreeNode* root, int x, int y) {
        int depth = 0;
        vector<Node> solution;
        
        queue<Node> q;
        q.push({0, -1, root});
        while(!q.empty()) {
            int levelNodes = q.size();
            depth++;
            for(int i = 0; i < levelNodes; ++i) {
                Node n = q.front(); q.pop();
                if(n.node->val == x || n.node->val == y) {
                    solution.push_back(n);
                    if(solution.size() == 2) break;
                }
                if(n.node->left) q.push({depth, n.node->val, n.node->left});
                if(n.node->right) q.push({depth, n.node->val, n.node->right});
            }
            
        }
        return solution[0].depth == solution[1].depth && solution[0].parent_val != solution[1].parent_val;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Cousins in Binary Tree.
// Memory Usage: 11.2 MB, less than 6.70% of C++ online submissions for Cousins in Binary Tree.