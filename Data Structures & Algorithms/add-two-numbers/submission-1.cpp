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
    void populateRemainderSum(ListNode* head, ListNode* tail, int &carry) {
        while(head) {
            int res = head->val + carry;
            tail->next = new ListNode(res%10);
            carry = res/10;
            tail = tail->next;
            head = head->next;
        }
        if(carry) tail->next = new ListNode(carry);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode dummy = ListNode(0);
        ListNode *tail = &dummy;
        while(l1 and l2) {
            int num = l2->val + l1->val, res = num + carry;
            tail->next = new ListNode(res%10);
            carry = res/10;
            tail = tail->next;
            l1 = l1->next;
            l2 = l2->next;
        }    
        if(l1) populateRemainderSum(l1, tail, carry);
        else populateRemainderSum(l2, tail, carry);
        return dummy.next;
    }
};
