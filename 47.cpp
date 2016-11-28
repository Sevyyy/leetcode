class Solution {
public:
    void dfs(vector<vector<int>> &ans, vector<int> &nums, int *used, vector<int> temp)
        {
            if(temp.size() == nums.size())
            {
                ans.push_back(temp);
                return;
            }
            for(int i = 0;i < nums.size();i++)
            {
                if(used[i])
                    continue;
                else if(i > 0 && nums[i] == nums[i-1] && used[i-1])
                {
                    continue;
                }
                else
                {
                    temp.push_back(nums[i]);
                    used[i] = 1;
                    dfs(ans, nums, used, temp);
                    used[i] = 0;
                    temp.pop_back();
                }
            }
        }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        int * used = new int[n];
        for(int i = 0;i < n;i++)
        {
            used[i] = 0;
        }
        vector<int> temp;
        dfs(ans, nums, used, temp);
        return ans;
    }
};