/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> nodeMap;
public:

    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        if(nodeMap[node]) return nodeMap[node];
        else {
            Node* newNode = new Node(node->val);
            nodeMap[node] = newNode;
            for(auto &nbr : node->neighbors) {
                newNode->neighbors.push_back(cloneGraph(nbr));
            }
            return newNode;
        }
    }
};
