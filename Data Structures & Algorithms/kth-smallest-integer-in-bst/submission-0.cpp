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
    // Inorder Time O(n) Space O(n)
    void populateInorderValues(TreeNode* root, vector<int>& inorderNodeValues) {
        if(!root) return;
        populateInorderValues(root->left, inorderNodeValues);
        inorderNodeValues.push_back(root->val);
        populateInorderValues(root->right, inorderNodeValues);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorderNodeValues;
        populateInorderValues(root, inorderNodeValues);
        return inorderNodeValues[k - 1];
    }
};
