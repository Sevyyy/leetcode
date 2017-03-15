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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        vector<TreeNode*> q;
        q.push_back(root);
        vector<int> t;
        t.push_back(root->val);
        ans.push_back(t);
        int index = 0;
        int len = 1;
        while(index < q.size())
        {
            vector<int> temp;
            int l = 0;
            for(int i = index; i < index+len; i++)
            {
                if(q[i]->left)
                {
                    q.push_back(q[i]->left);
                    temp.push_back(q[i]->left->val);
                    l++;
                }
                if(q[i]->right)
                {
                    q.push_back(q[i]->right);
                    temp.push_back(q[i]->right->val);
                    l++;
                }
            }
            if(temp.size())
                ans.push_back(temp);
            index += len;
            len = l;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};