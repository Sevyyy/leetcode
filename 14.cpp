class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if(strs.size() == 0)
            return ans;
        ans = strs.back();
        strs.pop_back();
        while(strs.size())
        {
            string temp = strs.back();
            strs.pop_back();
            int n = min(temp.size(), ans.size());
            if(n == 0)
            {
                ans = "";
                return ans;
            }
            bool flag = true;
            for(int i = 0;i < n; i++)
            {
                if(temp[i] != ans[i])
                {
                    ans = ans.substr(0,i);
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                ans = ans.substr(0,n);
            }
        }
        return ans;
    }
};