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
    bool helper(TreeNode *p, TreeNode* q)
    {
        if((p->left && q->left && helper(p->left, q->left)) || (p->left == NULL && q->left == NULL))
            ;
        else
            return false;
            
        if(p->val != q->val)
            return false;
            
        if((p->right && q->right && helper(p->right, q->right)) || (p->right == NULL && q->right == NULL))
            ;
        else
            return false;
            
        return true;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;
        if(p == NULL || q == NULL)
            return false;
        return helper(p,q);
    }
};