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
    // BFS Time O(n) Space O(n)
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> levelOrderQueue;
        if(root) levelOrderQueue.push(root);
        while(levelOrderQueue.size()) {
            TreeNode* frontNode = levelOrderQueue.front();
            levelOrderQueue.pop();
            swap(frontNode->left, frontNode->right);
            if(frontNode->left) levelOrderQueue.push(frontNode->left);
            if(frontNode->right) levelOrderQueue.push(frontNode->right);            
        }
        return root;
    }
};
