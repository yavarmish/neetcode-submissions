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
    // DFS Time O()
    bool validateBSTUsingMinMax(TreeNode* root, int leftMax, int rightMin) {
        if(!root) return true;
        if(root->val >= leftMax or root->val <= rightMin) return false;
        else return validateBSTUsingMinMax(root->left, root->val, rightMin) and validateBSTUsingMinMax(root->right, leftMax, root->val);
    }
    bool isValidBST(TreeNode* root) {
        return validateBSTUsingMinMax(root, INT_MAX, INT_MIN);        
    }
};
