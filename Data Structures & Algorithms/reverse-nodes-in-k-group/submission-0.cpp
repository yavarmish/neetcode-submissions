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
    /*
        Recursion(bottom up i.e. reverse the last group and recursively reverse the remaining ones)
        - Get the current tail
        - If current group has size less than k return it as it is
        - Reverse the remaining groups recursively storing the result in tail
        - Reverse the current group manually and return the tail
    */
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *tail = head;
        int groupSize = 0;
        while(tail and groupSize < k) {
            tail = tail->next;
            ++groupSize;
        }
        if(groupSize < k) return head;
        else {
            tail = reverseKGroup(tail, k); // tail is initially the result of recursion without reversing the current group
            while(groupSize > 0) {
                ListNode *next = head->next;
                head->next = tail;
                tail = head;
                head = next;
                --groupSize;
            }
            return tail; // tail is now the new head of the reversed group
        }
    }
};
