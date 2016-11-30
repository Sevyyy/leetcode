class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        int sum = nums[n-1];
        int maxSum = sum;

        for (int i = n - 2; i >= 0; i--) 
        {
            sum = max(nums[i], sum+nums[i]);
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};