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
    TreeNode* helper(vector<int> &inorder, int start1, int end1, vector<int> &postorder, int start2, int end2)
    {
        if(end1 < start1)
            return NULL;
        TreeNode *root = new TreeNode(postorder[end2]);
        if(start1 == end1)
            return root;
        int len = 0;
        while(inorder[len+start1] != postorder[end2])
        {
            len++;
        }
        if(len > 0)
        {
            root->left = helper(inorder, start1, start1+len-1, postorder, start2, start2+len-1);
        }
        if(end1-start1-len>0)
        {
            root->right = helper(inorder, start1+len+1, end1, postorder, start2+len, end2-1);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};