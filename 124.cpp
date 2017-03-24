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
    int helper(TreeNode* root)
    {
        if(!root->left && !root->right)
        {
            ans = max(ans, root->val);
            return root->val;
        }
        int left = 0;
        int right = 0;
        if(root->left)
            left = helper(root->left);
        if(root->right)
            right = helper(root->right);
        
        if(left >= 0 && right >= 0)
        {
            ans = max(ans, root->val + left + right);
            return root->val + max(left, right);
        }
        else if(left >= 0 || right >= 0)
        {
            ans = max(ans, root->val + max(left, right));
            return root->val + max(left, right);
        }
        else
        {
            ans = max(ans, root->val);
            return root->val;
        }
    }
    
    int maxPathSum(TreeNode* root) {
        if(!root)
            return 0;
        ans = INT_MIN;
        helper(root);
        return ans;    
    }
};