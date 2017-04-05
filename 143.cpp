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
    void reorderList(ListNode* head) {
        if(!head)
            return;
        vector<ListNode*> l;
        ListNode* cur = head;
        while(cur)
        {
            l.push_back(cur);
            cur = cur->next;
        }
        int n = l.size();
        for(int i = 0;i < n/2;i++)
        {
            l[i]->next = l[n-i-1];
            l[n-i-1]->next = l[i+1];
        }
        l[n/2]->next = NULL;
        return;
    }
};