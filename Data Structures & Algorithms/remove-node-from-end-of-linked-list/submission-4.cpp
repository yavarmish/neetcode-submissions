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
    // 2 pointers, one pointer n steps ahead of the other in the beginning, as it reaches the end we are on the node to be removed
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *cur = head, *nthCur = head;
        while(n--) {
            nthCur = nthCur->next;
        }
        // first node is to be removed
        if(!nthCur) {
            head = head->next;
            return head;
        }
        while(nthCur->next) {
            cur = cur->next;
            nthCur = nthCur->next;
        }
        cur->next = cur->next->next;
        return head;
    }
};
