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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode dummy = ListNode(0);
        ListNode *tail = &dummy;
        while(l1 or l2 or carry) {
            int res = 0;
            if(l1) res += l1->val;
            if(l2) res += l2->val;
            if(carry) res += carry;

            tail->next = new ListNode(res%10);
            carry = res/10;
            
            tail = tail->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }    
        return dummy.next;
    }
};
