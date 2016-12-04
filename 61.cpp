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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        ListNode* ans;
        ListNode* temp = head;
        int n = 1;
        while(temp->next)
        {
            temp = temp->next;
            n++;
        }
        temp->next = head;
        for(int i = 0;i < n-k%n;i++)
        {
            head = head->next;
            temp = temp->next;
        }
        temp->next = NULL;
        return head;
    }
};