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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB){
            return NULL;
        }
        int lenA = 1;
        int lenB = 1;
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while(tempA->next){
            lenA++;
            tempA = tempA->next;
        }
        while(tempB->next){
            lenB++;
            tempB = tempB->next;
        }
        if(tempA != tempB){
            return NULL;
        }
        if(lenA > lenB){
            for(int i = 1;i <= lenA-lenB;i++){
                headA = headA->next;
            }
        }
        else if(lenB > lenA){
            for(int i = 1;i <= lenB-lenA;i++){
                headB = headB->next;
            }
        }
        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};