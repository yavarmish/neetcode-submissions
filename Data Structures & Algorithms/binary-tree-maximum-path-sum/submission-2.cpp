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
    /* 
        Greedy bottom up DFS Time O(n) Space O(n)
        Single path through any node would only contain the node value + max result of left or the right subtree
        Result through any given node would be sum of node value, results of left and right subtree 
    */
    int populateResultThroughPathSum(TreeNode* root, int &res) {
        if(!root) return 0;
        int leftPathSum = max(0, populateResultThroughPathSum(root->left, res));
        int rightPathSum = max(0, populateResultThroughPathSum(root->right, res));
        res = max(res, root->val + leftPathSum + rightPathSum);
        return root->val + max(leftPathSum, rightPathSum);
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        populateResultThroughPathSum(root, res);
        return res;
    }
};
