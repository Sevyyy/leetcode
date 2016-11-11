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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* temp = head;
        while(temp)
        {
            size++;
            temp = temp->next;
        }
        if(size == 1)
        {
            return NULL;
        }
        int index = size - n - 1;
        temp = head;
        if(index == -1)
        {
            return temp->next;
        }
        while(index--)
        {
            temp = temp->next;
        }
        if(temp->next)
        {
            temp->next = temp->next->next;
        }
        else
        {
            temp->next = NULL;
        }
        return head;
    }
};