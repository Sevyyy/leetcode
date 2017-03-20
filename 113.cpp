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
    vector<vector<int>> ans;
    vector<int> cur;
public:
    void DFS(TreeNode* root, int need)
    {
        if(!root->left && !root->right)
        {
            if(root->val == need)
            {
                cur.push_back(root->val);
                ans.push_back(cur);
                cur.pop_back();
                return;
            }
            else
                return;
        }
        cur.push_back(root->val);
        need -= root->val;
        if(root->left)
        {
            DFS(root->left, need);
        }
        if(root->right)
        {
            DFS(root->right, need);
        }
        cur.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root)
            return ans;
        DFS(root, sum);
        return ans;
    }
};