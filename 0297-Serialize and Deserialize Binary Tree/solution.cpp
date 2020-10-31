#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        queue<TreeNode*> q;
        if(root) q.push(root);
        
        while(!q.empty()) {
            TreeNode *tmp = q.front(); q.pop();
            if(tmp) {
                ss << tmp->val << ' ';
                q.push(tmp->left);
                q.push(tmp->right);
            } else {
                // if node is nullptr
                ss << "null ";
            }    
        }
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        stringstream ss(data);
        queue<TreeNode*> q;
        string r;
        ss >> r;
        
        TreeNode *root = new TreeNode(stoi(r));
        TreeNode *iterator = root;
        q.push(iterator);
        while(!q.empty()) {
            TreeNode *node = q.front(); q.pop();   
            // left
            if(ss.rdbuf()->in_avail() == 0) break; 
            ss >> r;
            if(r != "null") {
                // r is value
                iterator = new TreeNode(stoi(r));
                q.push(iterator);
                node->left = iterator;
            }
            // right
            if(ss.rdbuf()->in_avail() == 0) break;
            ss >> r;
            if(r != "null") {
                // r is value
                iterator = new TreeNode(stoi(r));
                q.push(iterator);
                node->right = iterator;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

// Runtime: 40 ms, faster than 99.38% of C++ online submissions for Serialize and Deserialize Binary Tree.
// Memory Usage: 31.4 MB, less than 5.15% of C++ online submissions for Serialize and Deserialize Binary Tree.