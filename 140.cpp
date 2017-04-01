class Solution {
private:
    vector<string> ans;
public:
    bool breakable(string s, vector<string>& wordDict) {
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
    void dfs(string str, vector<vector<string>> &dp, int now)
    {
        if(now == 0)
        {
            ans.push_back(str.substr(0,str.size()-1));
            return;
        }
        for(auto it = dp[now].begin(); it != dp[now].end(); it++)
        {
            string new_str = *it + " " + str;
            dfs(new_str, dp, now - it->size());
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(!breakable(s, wordDict))
            return ans;
        int n = s.size();
        vector<vector<string>> dp(n+1);
        dp[0].push_back("");
        for(int i = 0;i < n;i++)
        {
            for(int j = 1;j + i <= n;j++)
            {
                if(find(wordDict.begin(), wordDict.end(), s.substr(i,j)) != wordDict.end())
                {
                    dp[i+j].push_back(s.substr(i, j));
                }
            }
        }
        dfs("", dp, n);
        return ans;
    }
};