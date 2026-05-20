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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy = ListNode(0);
        ListNode *tail = &dummy;

        while(1) {
            int minVal = INT_MAX, minIdx = -1;
            for(int i = 0; i < lists.size(); ++i) {
                if(lists[i] != NULL and lists[i]->val < minVal) {
                    minVal = lists[i]->val;
                    minIdx = i;
                }
            }
            if(minIdx == -1) break;
            lists[minIdx] = lists[minIdx]->next;
            tail->next = new ListNode(minVal);
            tail = tail->next;
        }    
        return dummy.next;
    }
};
