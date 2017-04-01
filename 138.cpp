/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)
            return NULL;
        map<int, RandomListNode*> m;
        RandomListNode * ans = new RandomListNode(head->label);
        RandomListNode * cur = ans;
        RandomListNode * ori = head;
        m[head->label] = cur;
        while(ori->next || ori->random)
        {
            if(ori->random)
            {
                if(m.find(ori->random->label) == m.end())
                {
                    RandomListNode * temp = new RandomListNode(ori->random->label);
                    cur->random = temp;
                    m[temp->label] = temp;
                }
                else
                {
                    cur->random = m[ori->random->label];
                }
            }
            if(ori->next)
            {
                if(m.find(ori->next->label) == m.end())
                {
                    RandomListNode * temp = new RandomListNode(ori->next->label);
                    cur->next = temp;
                    m[temp->label] = temp;
                }
                else
                {
                    cur->next = m[ori->next->label];
                }
                cur = cur->next;
                ori = ori->next;
            }
            else
                break;
        }
        return ans;
    }
};