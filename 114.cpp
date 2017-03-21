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
    void flatten(TreeNode* root) {
        if(!root)
            return;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* last = NULL;
        while(!s.empty())
        {
            TreeNode* cur = s.top();
            s.pop();
            if(cur->right)
                s.push(cur->right);
            if(cur->left)
                s.push(cur->left);
            if(!last)
            {
                last = cur;
                last->left = NULL;
            }
            else
            {
                last->right = cur;
                cur->left = NULL;
                cur->right = NULL;
                last = cur;
            }
        }
        return;
    }
};