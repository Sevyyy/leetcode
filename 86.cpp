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
    ListNode* partition(ListNode* head, int x) {
        ListNode *small = new ListNode(0);
        ListNode *smalll = small;
        ListNode *big = new ListNode(0);
        ListNode *bigg = big;
        ListNode *cur = head;
        while(cur)
        {
        	if(cur->val < x)
        	{
        		small->next = cur;
        		small = small->next;
        	}
        	else
        	{
        		big->next = cur;
        		big = big->next;
        	}
        	cur = cur->next;
        }
        small->next = bigg->next;
        big->next = NULL;
        return smalll->next;
    }
};