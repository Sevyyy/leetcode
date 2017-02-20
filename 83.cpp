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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *ans = new ListNode(0);
        ans->next = head;
        ListNode* cur = head;
        if(!cur)
            return ans->next;
        while(cur->next)
        {
            if(cur->val != cur->next->val)
            {
                cur = cur->next;
            }
            else
            {
                cur->next = cur->next->next;
            }
        }
        return ans->next;
    }
};