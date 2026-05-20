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
    // Check if balanced while updating heights Time O(n) Space O(h)
    int checkIfBalancedUsingDepth(TreeNode* root, bool &res) {
        if(!root) return 0;
        int leftHeight = checkIfBalancedUsingDepth(root->left, res);        
        int rightHeight = checkIfBalancedUsingDepth(root->right, res);
        if(abs(leftHeight - rightHeight) > 1) res = false;
        return 1 + max(leftHeight, rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        bool res = true;
        checkIfBalancedUsingDepth(root, res);
        return res;
    }
};
