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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* cur;
        while(!s.empty())
        {
            cur = s.top();
            s.pop();
            ans.push_back(cur->val);
            while(cur)
            {
                if(cur->right)
                    s.push(cur->right);
                cur = cur->left;
                if(cur)
                    ans.push_back(cur->val);
            }
        }
        return ans;
    }
};