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
    unordered_map<int, int> inorderIndices;
    int preIdx = 0;
public:
    TreeNode* createTreeUsingInorderAndPreorder(int inorderLow, int inorderHigh, vector<int> &inorder, vector<int>& preorder) {
        // Base case
        if(inorderLow > inorderHigh) return NULL;
        // Recursion
        int currentRootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(currentRootVal);
        root->left = createTreeUsingInorderAndPreorder(inorderLow, inorderIndices[currentRootVal] - 1, inorder, preorder);
        root->right = createTreeUsingInorderAndPreorder(inorderIndices[currentRootVal] + 1, inorderHigh, inorder, preorder);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); ++i) {
            inorderIndices[inorder[i]] = i;
        }

        TreeNode* newRoot = createTreeUsingInorderAndPreorder(0, inorder.size() - 1, inorder, preorder);
        return newRoot;
    }
};
