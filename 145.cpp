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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        stack<pair<TreeNode*, int> > s;
        pair<TreeNode*, int> cur(root, 1);
        do
        {
            while(cur.first)
            {
                s.push(cur);
                cur = pair<TreeNode*, int>(cur.first->left, 1);
            }
            bool out = false;
            while(!out && !s.empty())
            {
                cur = s.top();
                s.pop();
                if(cur.second == 1)
                {
                    cur.second = 2;
                    s.push(cur);
                    cur = pair<TreeNode*, int>(cur.first->right, 1);
                    out = true;
                }
                else if(cur.second == 2)
                {
                    ans.push_back(cur.first->val);
                }
            }
        }while(!s.empty());
        return ans;
    }
};