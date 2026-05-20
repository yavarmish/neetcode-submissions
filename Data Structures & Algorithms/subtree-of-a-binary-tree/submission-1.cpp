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
    bool isSame(TreeNode* p, TreeNode* q) {
        if(!p and !q) return true;
        else if(!p or !q) return false;
        else if(p->val != q->val) return false;
        else return isSame(p->left, q->left) and isSame(p->right, q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        else if(isSame(root, subRoot)) return true;
        else return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }
};
