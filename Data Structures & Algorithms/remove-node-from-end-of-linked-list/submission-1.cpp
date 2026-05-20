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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode *cur = head;
        while(cur) {
            ++len;
            cur = cur->next;
        }
        int startPos = len - n;
        ListNode *prevNode = NULL;
        while(startPos > 0) {
            --startPos;
            if(prevNode) prevNode = prevNode->next;
            else prevNode = head;
        }
        if(!prevNode) head = head->next;
        else prevNode->next = prevNode->next->next;
        return head;
    }
};
