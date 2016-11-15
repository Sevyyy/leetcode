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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1)
            return head;
        ListNode * ans = new ListNode(-1);
        ans->next = head;
        head = ans;
        int n = 0;
        while(head->next)
        {
            n++;
            head = head->next;
        }
        head = ans;
        int times = n / k;
        for(int t = 0;t < times; t++)
        {
            ListNode * lasthead = head;
            ListNode * last = head->next;
            ListNode * cur = last->next;
            ListNode * next = cur->next;
            for(int i = 0;i < k-2;i++)
            {
                cur->next = last;
                last = cur;
                cur = next;
                next = next->next;
            }
            cur->next = last;
            lasthead->next->next = next;
            head = lasthead->next;
            lasthead->next = cur; 
        }
        return ans->next;
    }
};