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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int size = n-m;
        ListNode* forehead = new ListNode(-1);
        forehead->next = head;
        ListNode* start = forehead;
        for(int i = 1;i < m;i++)
        {
            start = start->next;
        }
        ListNode* last = start?start->next:NULL;
        ListNode* cur = last?last->next:NULL;
        ListNode* next = cur?cur->next:NULL;
        for(int i = 0;i < size;i++)
        {
            cur->next = last;
            last = cur;
            cur = next;
            next = next?next->next:NULL;
        }
        start->next->next = cur;
        start->next = last;
        return forehead->next;
    }
};