/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* sorted = new ListNode(-1);
        while(head)
        {
            ListNode* temp = head->next;
            ListNode* cur = sorted;
            while(cur->next && cur->next->val < head->val)
            {
                cur = cur->next;
            }
            head->next = cur->next;
            cur->next = head;
            head = temp;
        }
        return sorted->next;
    }
};