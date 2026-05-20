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
    // Bruteforce Time O(n^2) Space O(h)
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    void getDiameterUsingDepth(TreeNode* root, int &res) {
        if(!root) return;
        int leftDepth = maxDepth(root->left), rightDepth = maxDepth(root->right);
        res = max(res, leftDepth + rightDepth);
        getDiameterUsingDepth(root->left, res);
        getDiameterUsingDepth(root->right, res);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        getDiameterUsingDepth(root, res);
        return res;
    }
};