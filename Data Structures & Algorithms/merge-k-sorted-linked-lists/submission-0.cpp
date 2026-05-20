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
    // Bruteforce, sort all elements in a vector, create a new list of them
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> listVector;
        for(ListNode* list : lists) {
            while(list) {
                listVector.push_back(list->val);
                list = list->next;
            }
        }
        sort(listVector.begin(), listVector.end());
        ListNode dummy = ListNode(0);
        ListNode *tail = &dummy;

        for(int val : listVector) {
            tail->next = new ListNode(val);
            tail = tail->next;
        }
        return dummy.next;
    }
};
