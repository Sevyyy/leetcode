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
    vector<TreeNode*> helper(int left, int right)
    {
        vector<TreeNode*> ans;
        if(left > right)
        {
            ans.push_back(NULL);
            return ans;
        }
        for(int i = left; i <= right; i++)
        {
            vector<TreeNode*> l = helper(left, i-1);
            vector<TreeNode*> r = helper(i+1, right);
            for(int j = 0; j < l.size(); j++)
            {
                for(int k = 0; k < r.size(); k++)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = l[j];
                    root->right = r[k];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)
            return vector<TreeNode*>{};
        return helper(1,n);
    }
};