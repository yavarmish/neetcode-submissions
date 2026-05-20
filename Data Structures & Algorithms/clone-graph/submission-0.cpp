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
public:
    // Hashmap + DFS Time O(V + E) Space O(V)    
    Node* copyGraphUsingDFS(Node* node, unordered_map<Node*, Node*>& oldNodeToNewNodeMapping) {
        if(!node) return NULL;
        else if(oldNodeToNewNodeMapping[node]) return oldNodeToNewNodeMapping[node];
        else {
            Node* newNode = new Node(node->val);
            oldNodeToNewNodeMapping[node] = newNode;
            for(Node* neighborNode : node->neighbors) {
                newNode->neighbors.push_back(copyGraphUsingDFS(neighborNode, oldNodeToNewNodeMapping));
            }
            return newNode;
        }
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> oldNodeToNewNodeMapping;
        return copyGraphUsingDFS(node, oldNodeToNewNodeMapping);        
    }
};
