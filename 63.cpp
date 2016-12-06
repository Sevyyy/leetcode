class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int dp[100][100];
        if(obstacleGrid[0][0] == 1)
            return 0;
        dp[0][0] = 1;
        for(int i = 1;i < n;i++)
        {
            dp[0][i] = obstacleGrid[0][i]?0:dp[0][i-1];
        }
        for(int i = 1;i < m;i++)
        {
            dp[i][0] = obstacleGrid[i][0]?0:dp[i-1][0];
        }
        for(int i = 1;i < m;i++)
        {
            for(int j = 1;j < n;j++)
            {
                dp[i][j] = obstacleGrid[i][j]?0:dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};