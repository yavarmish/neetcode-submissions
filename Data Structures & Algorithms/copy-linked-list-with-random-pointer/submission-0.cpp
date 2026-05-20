/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> oldNodeToNewNodeMapping;
        Node *cur = head;
        while(cur) {
            oldNodeToNewNodeMapping[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        while(cur) {
            Node* copyNode = oldNodeToNewNodeMapping[cur];
            copyNode->next = oldNodeToNewNodeMapping[cur->next];
            copyNode->random = oldNodeToNewNodeMapping[cur->random];
            cur = cur->next;
        }
        return oldNodeToNewNodeMapping[head];
    }
};
