class Solution {
public:
    string minWindow(string s, string t) {
        int need[256] = {0};
        for(int i = 0;i < t.size();i++)
            need[t[i]] ++;
        int found[256] = {0};
        int begin = 0;
        int end = 0;
        int ans = INT_MAX;
        string ret = "";
        int count = 0;
        for(;end < s.size();end++)
        {
            if(need[s[end]] == 0)
                continue;
            found[s[end]]++;
            if(found[s[end]] <= need[s[end]])
                count++;
            if(count >= t.size())
            {
                while(need[s[begin]] == 0 || found[s[begin]] > need[s[begin]])
                {
                    if(found[s[begin]] > need[s[begin]])
                        found[s[begin]]--;
                    begin++;
                }
                if(end-begin+1 < ans)
                {
                    ans = end-begin+1;
                    ret = s.substr(begin, ans);
                }
            }
            
        }
        return ret;
    }
};