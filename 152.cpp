class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        if(n == 1)
            return nums[0];
        int ans = nums[0];
        int max_ = nums[0];
        int min_ = nums[0];
        for(int i = 1;i < n;i++)
        {
            int a = max_*nums[i];  
            int b = min_*nums[i];  
              
            max_ = max(nums[i], max(a, b));  
            min_ = min(nums[i], min(a, b));  
            ans = max(max_, ans);  
        }
        return ans;
    }
};