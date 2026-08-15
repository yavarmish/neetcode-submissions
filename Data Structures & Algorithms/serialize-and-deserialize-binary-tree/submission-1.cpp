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

class Codec {

    void levelOrderTraversal(TreeNode* root, string &res) {
        if(!root) return;
        queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);

        while(bfsQueue.size()) {
            TreeNode* frontNode = bfsQueue.front();
            bfsQueue.pop();
            
            if(frontNode) {
                res += (to_string(frontNode->val) + " ");
                bfsQueue.push(frontNode->left);
                bfsQueue.push(frontNode->right);
            }
            else {
                res += "null ";
            }
        }
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        levelOrderTraversal(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        stringstream dataStream(data);
        string val;
        dataStream >> val;
        TreeNode* root = new TreeNode(stoi(val));
        if(root == NULL) return NULL;
        queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);

        while(dataStream >> val) {
            TreeNode* node = bfsQueue.front();
            bfsQueue.pop();

            if(val != "null") {
                node->left = new TreeNode(stoi(val));
                bfsQueue.push(node->left);
            }
            dataStream >> val;
            if(val != "null") {
                node->right = new TreeNode(stoi(val));
                bfsQueue.push(node->right);
            }
        }
        return root;
    }
};
