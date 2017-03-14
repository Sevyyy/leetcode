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
    TreeNode* helper(vector<int> &preorder, int start1, int end1, vector<int> &inorder, int start2, int end2)
    {
        if(end1 < start1)
            return NULL;
        TreeNode *root = new TreeNode(preorder[start1]);
        if(start1 == end1)
            return root;
        int len = 0;
        while(inorder[len+start2] != preorder[start1])
        {
            len++;
        }
        if(len > 0)
        {
            root->left = helper(preorder, start1+1, start1+len, inorder, start2, start2+len-1);
        }
        if(end1-start1-len>0)
        {
            root->right = helper(preorder, start1+len+1, end1, inorder, start2+len+1, end2);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};