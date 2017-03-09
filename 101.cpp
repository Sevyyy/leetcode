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
        if((p->left && q->right && helper(p->left, q->right)) || (p->left == NULL && q->right == NULL))
            ;
        else
            return false;
            
        if(p->val != q->val)
            return false;
            
        if((p->right && q->left && helper(p->right, q->left)) || (p->right == NULL && q->left == NULL))
            ;
        else
            return false;
            
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        if(root->left && root->right && helper(root->left, root->right))
            return true;
        if(root->left == NULL && root->right == NULL)
            return true;
        return false;
    }
};