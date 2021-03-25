class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> Q;
        Q.push(root);
        TreeNode *node;

        while(!Q.empty()) {
            int q_size = Q.size();
            while(q_size--) {
                node = Q.front();
                Q.pop();
                if(node->right) Q.push(node->right);
                if(node->left) Q.push(node->left);
            }
        }
        return node->val;
    }
};