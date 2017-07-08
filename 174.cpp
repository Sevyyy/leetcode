class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        dp[m-1][n-1] = max(1,1-v[m-1][n-1]);
        for(int i = n-2;i >= 0;i--){
            dp[m-1][i] = max(1,dp[m-1][i+1]-v[m-1][i]);
        }
        for(int j = m-2;j >= 0;j--){
            dp[j][n-1] = max(1,dp[j+1][n-1]-v[j][n-1]);
        }
        for(int i = m-2;i >= 0;i--){
            for(int j = n-2;j >= 0;j--){
                dp[i][j] = max(1,min(dp[i][j+1]-v[i][j],dp[i+1][j]-v[i][j]));
            }
        }
        return dp[0][0];
    }
};