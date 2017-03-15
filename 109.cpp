/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(ListNode* head, int n)
    {
        if(n <= 0)
            return NULL;
        int mid = n/2;
        ListNode* key = head;
        for(int i = 0;i < mid;i++)
        {
            key = key->next;
        }
        TreeNode* root = new TreeNode(key->val);
        root->left = helper(head, mid);
        root->right = helper(key->next, n-mid-1);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        while(temp)
        {
            temp = temp->next;
            n++;
        }
        TreeNode *root = helper(head, n);
        return root;
    }
};