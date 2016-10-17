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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode * l11 = l1;
        ListNode * l22 = l2;
        ListNode * ans = new ListNode(0);
        ListNode * ans_p = ans;
        int excess = 0;
        while(l11 != NULL || l22 != NULL)
        {
            int v1, v2;
            
            if(l11 != NULL)
                v1 = l11->val;
            else
                v1 = 0;
                
            if(l22 != NULL)
                v2 = l22->val;
            else
                v2 = 0;
                
            ans_p->next = new ListNode((v1 + v2 + excess) % 10);
            excess = (v1 + v2 + excess) / 10;
            
            if(l11 != NULL)
                l11 = l11->next;
            if(l22 != NULL)
                l22 = l22->next;
            ans_p = ans_p->next;
        }
        if(excess == 1)
        {
            ans_p->next = new ListNode(1);
        }
        
        return ans->next;

    }
};
