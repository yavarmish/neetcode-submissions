/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    // Hashmap Time O(n) Space O(n)
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> seenNodes;
        while(head) {
            if(seenNodes.count(head)) return true;
            seenNodes.insert(head);
            head = head->next;
        }
        return false;
    }
};
