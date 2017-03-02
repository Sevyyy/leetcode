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
    void readchild(vector<int> &ans, TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }
        else
        {
            readchild(ans, root->left);
            ans.push_back(root->val);
            readchild(ans, root->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        readchild(ans, root);
        return ans;
    }
};