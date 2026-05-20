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
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> dfsStack;
        if(root) dfsStack.push(root);
        while(dfsStack.size()) {
            TreeNode* frontNode = dfsStack.top();
            dfsStack.pop();
            swap(frontNode->left, frontNode->right);
            if(frontNode->left) dfsStack.push(frontNode->left);
            if(frontNode->right) dfsStack.push(frontNode->right);
        }
        return root;
    }
};
