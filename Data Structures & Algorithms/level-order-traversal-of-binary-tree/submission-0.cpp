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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levelOrderResult;
        queue<TreeNode*> levelOrderQueue;
        if(root) levelOrderQueue.push(root);
        while(levelOrderQueue.size()) {
            int k = levelOrderQueue.size();     
            vector<int> currentLevel;       
            while(k--) {
                TreeNode* frontNode = levelOrderQueue.front();
                levelOrderQueue.pop();
                currentLevel.push_back(frontNode->val);
                if(frontNode->left) levelOrderQueue.push(frontNode->left);
                if(frontNode->right) levelOrderQueue.push(frontNode->right);
            }
            levelOrderResult.push_back(currentLevel);
        }
        return levelOrderResult;
    }
};
