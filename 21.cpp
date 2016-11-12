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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * ans = new ListNode(0);
        ListNode * head = ans;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                ans->next = new ListNode(l1->val);
                ans = ans->next;
                l1 = l1->next;
            }
            else
            {
                ans->next = new ListNode(l2->val);
                ans = ans->next;
                l2 = l2->next;
            }
        }
        while(l1)
        {
            ans->next = new ListNode(l1->val);
            ans = ans->next;
            l1 = l1->next;
        }
        while(l2)
        {
            ans->next = new ListNode(l2->val);
            ans = ans->next;
            l2 = l2->next;
        }
        return head->next;
    }
};