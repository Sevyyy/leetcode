class Solution {
public:
    bool valid(string s)
    {
        int n = s.size();
        for(int i = 0;i < n/2;i++)
        {
            if(s[i] != s[n-i-1])
                return false;
        }
        return true;
    }
    void dfs(string s, vector<vector<string>> &ans, vector<string> cur)
    {
        int n = s.size();
        for(int i = 1;i <= n;i++)
        {
            string temp = s.substr(0,i);
            if(valid(temp))
            {
                cur.push_back(temp);
                if(i == n)
                {
                    ans.push_back(cur);
                }
                else
                {
                    dfs(s.substr(i), ans, cur);
                }
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur;
        dfs(s, ans, cur);
        return ans;
    }
};