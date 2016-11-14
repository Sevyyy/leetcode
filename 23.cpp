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
    struct cmp
    {
        bool operator()(ListNode *a,ListNode *b)
        {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode *ans = new ListNode(0);
        ListNode *cur = ans;
        priority_queue<ListNode*, vector<ListNode*>, cmp> l;
        for(int i = 0;i < n;i++)
        {
            if(lists[i])
                l.push(lists[i]);
        }
        while(l.size())
        {
            ListNode *temp = l.top();
            l.pop();
            cur->next = new ListNode(temp->val);
            cur = cur->next;
            if(temp->next)
                l.push(temp->next);
        }
        //cur->next = NULL;
        return ans->next;
    }
};