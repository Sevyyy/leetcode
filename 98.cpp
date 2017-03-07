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
    void DFS(TreeNode* root, vector<int> &tree)
    {
        if(root->left)
            DFS(root->left, tree);
        tree.push_back(root->val);
        if(root->right)
            DFS(root->right, tree);
    }
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        vector<int> tree;
        DFS(root, tree);
        int n = tree.size();
        for(int i = 1;i < n;i++)
        {
            if(tree[i] <= tree[i-1])
                return false;
        }
        return true;
    }
};