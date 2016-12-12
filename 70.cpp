class Solution {
public:
    int climbStairs(int n) {
        if(n == 0)
            return 0;
        else if(n == 1)
            return 1;
        int *dp = new int[n];
        dp[0] = 1;
        dp[1] = 2;
        for(int i = 2;i < n;i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        int ans = dp[n-1];
        delete[] dp;
        return ans;
    }
};