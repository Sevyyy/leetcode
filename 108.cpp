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
    TreeNode* helper(vector<int>& nums, int start, int end)
    {
        if(end < start)
            return NULL;
        int mid = (end+start)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        if(start == end)
            return root;
        root->left = helper(nums, start, mid-1);
        root->right = helper(nums, mid+1, end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
};