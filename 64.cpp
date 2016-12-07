class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int *dp = new int[m*n];
        dp[0] = grid[0][0];
        for(int i = 1;i < n;i++)
            dp[0*n+i] = grid[0][i] + dp[0*n+i-1];
        for(int i = 1;i < m;i++)
            dp[i*n+0] = grid[i][0] + dp[(i-1)*n+0];
        for(int i = 1;i < m;i++)
        {
            for(int j = 1;j < n;j++)
            {
                dp[i*n+j] = min(dp[(i-1)*n+j] + grid[i][j], dp[i*n + j-1] + grid[i][j]);
            }
        }
        int a = dp[(m-1)*n+(n-1)];
        delete[] dp;
        return a;
    }
};