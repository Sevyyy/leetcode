class Solution {
public:
	void dfs(vector<vector<int>> &ans, vector<int> &cur, vector<int>& nums, int n, int pos)
	{
		if(pos == n)
			return;
		for(int i = pos;i < n;i++)
		{
			if(i == pos || i > pos && nums[i] != nums[i-1])
			{
				cur.push_back(nums[i]);
				ans.push_back(cur);
				dfs(ans, cur, nums, n, i+1);
				cur.pop_back();
			}
		}
	}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        ans.push_back(temp);
        dfs(ans, temp, nums, nums.size(), 0);
        return ans;
    }
};