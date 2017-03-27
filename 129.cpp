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
private:
    int ans;
public:
    void dfs(int sum, TreeNode* root)
    {
        if(!root->left && !root->right)
        {
            ans += sum*10 + root->val;
            return;
        }
        else
        {
            if(root->left)
                dfs(sum*10+root->val, root->left);
            if(root->right)
                dfs(sum*10+root->val, root->right);
        }
        return;
    }
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        ans = 0;
        dfs(0,root);
        return ans;
    }
};