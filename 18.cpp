class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        if(n < 4)
            return ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                int k = j + 1;
                int l = n - 1;
                while(k < l)
                {
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum == target)
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        temp.push_back(nums[l]);
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k < l && nums[k] == nums[k-1])
                            k++;
                        while(k < l && nums[l] == nums[l+1])
                            l--;
                    }
                    else if(sum > target)
                    {
                        l--;
                    }
                    else if(sum < target)
                    {
                        k++;
                    }
                }
                while(j < n-1 && nums[j] == nums[j+1])
                    j++;
            }
            while(i < n-1 && nums[i] == nums[i+1])
                i++;
        }
        return ans;
    }
};