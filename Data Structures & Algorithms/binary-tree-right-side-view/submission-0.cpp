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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightView;
        queue<TreeNode*> levelOrderQueue;
        if(root) levelOrderQueue.push(root);
        while(levelOrderQueue.size()) {
            int k = levelOrderQueue.size();     
            while(k--) {
                TreeNode* frontNode = levelOrderQueue.front();
                levelOrderQueue.pop();
                if(k == 0) rightView.push_back(frontNode->val);
                if(frontNode->left) levelOrderQueue.push(frontNode->left);
                if(frontNode->right) levelOrderQueue.push(frontNode->right);
            }
        }
        return rightView;
    }
};
