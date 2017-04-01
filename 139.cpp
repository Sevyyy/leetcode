class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        if(n == 0)
            return true;
        if(wordDict.size() == 0)
            return false;
        vector<bool> dp(n+1,false);
        dp[0] = true;
        for(int i = 0;i < n;i++)
        {
            for(int j = i;j >= 0;j--)
            {
                string temp = s.substr(j,i-j+1);
                if(find(wordDict.begin(), wordDict.end(), temp) != wordDict.end())
                {
                    if(dp[j] == true)
                    {
                        dp[i+1] = true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};