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
    void reorderList(ListNode* head) {
        vector<ListNode*> listCopy;
        ListNode* curNode = head;
        while(curNode) {
            listCopy.push_back(curNode);
            curNode = curNode->next;
        }
        int start = 0, end = listCopy.size() - 1;
        while(start < end) {
            listCopy[start]->next = listCopy[end];
            listCopy[end]->next = listCopy[start + 1];
            ++start;
            --end;
        }
        listCopy[start]->next = NULL;
    } 
};
