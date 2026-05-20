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
    // DFS Time O(n) Space O(n)
    int countGoodNodes(TreeNode* root, int currentMax) {
        if(!root) return 0;
        int res = root->val >= currentMax, maxVal = max(currentMax, root->val);
        return res + countGoodNodes(root->left, maxVal) + countGoodNodes(root->right, maxVal);
    }
    int goodNodes(TreeNode* root) {
        return countGoodNodes(root, -1e4 - 1);
    }
};
