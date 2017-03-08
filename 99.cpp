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
    void DFS(TreeNode* &last, TreeNode *root, vector<TreeNode*> &ss)
    {
        if(root->left)
            DFS(last, root->left, ss);
        if(root->val < last->val)
        {
            if(ss.size() == 0)
            {
                ss.push_back(last);
                ss.push_back(root);
            }
            else
                ss[1] = root;
        }
        last = root;
        if(root->right)
            DFS(last, root->right, ss);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> ss;
        TreeNode *last = new TreeNode(INT_MIN);
        DFS(last, root, ss);
        if(ss.size() == 0)
            return;
        int temp = ss[0]->val;
        ss[0]->val = ss[1]->val;
        ss[1]->val = temp;
    }
};