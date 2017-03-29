class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if(n == 0)
            return 0;
        vector<vector<bool>> dp(n, vector<bool>(n,false));
        vector<int> min(n+1,-1);
        for(int i = 0;i < n;i++)
        {
            dp[i][i] = true;
        }
        for(int i = n-1;i >= 0;i--)
        {
            min[i] = min[i+1] + 1;
            for(int j = i+1;j < n;j++)
            {
                if(s[i] == s[j])
                {
                    if((j == i+1) || dp[i+1][j-1])
                    {
                        dp[i][j] = true;
                        if(j == n-1)
                            min[i] = 0;
                        else if(min[i] > min[j+1]+1)
                            min[i] = min[j+1] + 1;
                    }
                }
            }
        }
        return min[0];
    }
};