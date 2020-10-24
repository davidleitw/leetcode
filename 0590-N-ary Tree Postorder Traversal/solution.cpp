#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> solution;
        solve(root, solution);
        return solution;
    }
    
    void solve(Node* root, vector<int> &solution) {
        if(!root) return;
        if(!root->children.empty()) {
            for(int i = 0; i < root->children.size(); ++i) 
                solve(root->children[i], solution);
        }
        solution.push_back(root->val);
    }
};

// Runtime: 32 ms, faster than 98.81% of C++ online submissions for N-ary Tree Postorder Traversal.
// Memory Usage: 11.6 MB, less than 5.60% of C++ online submissions for N-ary Tree Postorder Traversal.