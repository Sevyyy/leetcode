class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        if(m == 0 || n == 0)
        {
            return m==0?n:m;
        }
        vector<vector<int>> dp;
        vector<int> temp;
        for(int i = 0;i <= n;i++)
            temp.push_back(0);
        for(int i = 0;i <= m;i++)
            dp.push_back(temp);
        for(int i = 0;i <= m;i++)
            dp[i][0] = i;
        for(int j = 0;j <= n;j++)
            dp[0][j] = j;
        for(int i = 1;i <= m;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                int d,in,r;
                if(word1[i-1] == word2[j-1])
                    r = dp[i-1][j-1];
                else
                    r = dp[i-1][j-1] + 1;
                d = dp[i-1][j] + 1;
                in = dp[i][j-1] + 1;
                dp[i][j] = min(min(d,in),r);
            }
        }
        return dp[m][n];
    }
};