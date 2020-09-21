#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    int getMinimumDifference(TreeNode* root) {    
        stack<TreeNode*> s;
        int prev_val = 0;
        bool prev_exist = false;
        int solution = INT_MAX;
        
        while(root != nullptr || !s.empty()) {
            if(root != nullptr) {
                s.push(root);
                root = root->left;
            } else {
                TreeNode *tmp = s.top();
                s.pop(); 
                if(prev_exist) {
                    solution = min(solution, tmp->val - prev_val);
                }
                prev_val = tmp->val;
                prev_exist = true;
                root = tmp->right;
            }
        }
        return solution;
    }
};

// Runtime: 12 ms, faster than 100.00% of C++ online submissions for Minimum Absolute Difference in BST.
// Memory Usage: 25.6 MB, less than 30.22% of C++ online submissions for Minimum Absolute Difference in BST.
