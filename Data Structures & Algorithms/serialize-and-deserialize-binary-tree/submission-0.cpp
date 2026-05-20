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
public:

    // Space seperated DFS values Time O(n) Space O(n)
    void populatePreorderString(TreeNode* root, string &res) {
        if(!root) {
            res += "N ";
            return;
        }
        res += to_string(root->val) + " ";
        populatePreorderString(root->left, res);
        populatePreorderString(root->right, res);
    }
    string serialize(TreeNode* root) {
        string res;
        populatePreorderString(root, res);
        return res;
    }

    TreeNode* deserializePreorderString(stringstream& dataStream) {
        string currentVal;
        dataStream >> currentVal;
        if(currentVal == "N") return NULL;
        TreeNode* root = new TreeNode(stoi(currentVal));
        root->left = deserializePreorderString(dataStream);
        root->right = deserializePreorderString(dataStream);
        return root;
    }
    TreeNode* deserialize(string data) {
        stringstream dataStream(data);
        return deserializePreorderString(dataStream);    
    }
};
