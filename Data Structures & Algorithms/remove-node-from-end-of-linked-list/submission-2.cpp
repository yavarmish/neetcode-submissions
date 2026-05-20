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
        int removalIdx = len - n;
        if(removalIdx == 0) {
            head = head->next;
            return head;
        }
        cur = head;
        while(removalIdx > 1) {
            cur = cur->next;
            --removalIdx;        
        }
        cur->next = cur->next->next;
        return head;
    }
};
