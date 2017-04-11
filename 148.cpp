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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *right_end = head;
        ListNode *right_head = head;
        ListNode *left_end = head;
        while(right_end)
        {
            left_end = right_head;
            right_end = right_end->next;
            right_head = right_head->next;
            if(right_end)
                right_end = right_end->next;
        }
        left_end->next = NULL;
        ListNode *left = sortList(head);
        ListNode *right = sortList(right_head);
        ListNode *ans = new ListNode(-1);
        ListNode *anss = ans;
        while(left && right)
        {
            if(left->val < right->val)
            {
                anss->next = left;
                left = left->next;
            }
            else
            {
                anss->next = right;
                right = right->next;
            }
            anss = anss->next;
            anss->next = NULL;
        }
        while(left)
        {
            anss->next = left;
            left = left->next;
            anss = anss->next;
        }
        while(right)
        {
            anss->next = right;
            right = right->next;
            anss = anss->next;
        }
        ListNode *ret = ans->next;
        delete ans;
        return ret;
    }
};