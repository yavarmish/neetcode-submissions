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
    // Finding mid, reversing list after mid and merging them alternately Time O(n) Space O(1)
    ListNode* getMid(ListNode* head) {
        ListNode* mid = head, *fast = head->next;
        while(fast and fast->next) {
            mid = mid->next;
            fast = fast->next->next;
        }
        return mid;
    }
    ListNode* reverse(ListNode* head) {
        ListNode *prev = NULL, *cur = head;
        while(cur) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    void alternateMerge(ListNode *list1, ListNode *list2) {
        ListNode *cur1 = list1, *cur2 = list2;
        while(cur1 and cur2) {
            ListNode *next1 = cur1->next;
            ListNode *next2 = cur2->next;

            cur1->next = cur2;
            cur2->next = next1;

            cur1 = next1;
            cur2 = next2;
        }
    }
    void reorderList(ListNode* head) {
        ListNode* mid = getMid(head);
        ListNode* reversedListHead = reverse(mid->next);
        mid->next = NULL;
        alternateMerge(head, reversedListHead);
    }
};
