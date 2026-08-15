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
        Morris Traversal Time -> O(n) Space -> O(1)
        Instead of relying on dfs stack for returning to the parent after child nodes are covered
        We create a bridge from right-most node in left subtree if it exists(also called the predecessor node) each time
        We destroy the bridge after iteration for left subtree is complete
    */
    int kthSmallest(TreeNode* root, int k) {
        TreeNode *cur = root;

        while(cur) {
            if(!cur->left) {
                --k;
                if(k == 0) return cur->val;
                cur = cur->right;
            }

            else {
                TreeNode* pred = cur->left;
                // pred->right != cur -> To avoid infinite loop if bridge exists
                while(pred->right and pred->right != cur) pred = pred->right;

                // Bridge already exists
                if(pred->right) {
                    --k;
                    if(k == 0) return cur->val;
                    // Do Same for right subtree
                    cur = cur->right;
                }
                // Set predecessor and iterate the left subtree
                else {
                    pred->right = cur;
                    cur = cur->left;
                }
            }
        }
        return -1;
    }
};
