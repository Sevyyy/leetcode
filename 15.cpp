class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        if(n < 3)
            return ans;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++)
        {
            while(i > 0 && i < n && nums[i] == nums[i-1])
                i++;
            int a = i + 1;
            int b = n - 1;
            while(a < b)
            {
                int sum = nums[a] + nums[b] + nums[i];
                if(sum > 0)
                {
                    b--;
                    while(nums[b+1] == nums[b] && a < b)
                        b--;
                }
                else if(sum < 0)
                {
                    a++;
                    while(nums[a-1] == nums[a] && a < b)
                        a++;
                }
                else
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[a]);
                    temp.push_back(nums[b]);
                    ans.push_back(temp);
                    a++;
                    b--;
                    while(nums[a-1] == nums[a] && a < b)
                        a++;
                    while(nums[b+1] == nums[b] && a < b)
                        b--;
                }
            }
        }
        return ans;
    }
};