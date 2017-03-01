class Solution {
public:
    void split(int num, string s, string &path, vector<string> & ans)
    {
        if(num == 4 && s.size() == 0)
        {
            ans.push_back(path.substr(0,path.size()-1));
            return;
        }
        
        if(s.size() > 3*(4-num))
        {
            return;
        }
        
        if(s.size() > 0)
        {
            path+=s.substr(0,1) + '.';
            split(num+1, s.substr(1), path, ans);
            path = path.substr(0,path.size()-2);
        }
        
        if(s.size() > 1 && s[0] != '0')
        {
            path+=s.substr(0,2) + '.';
            split(num+1, s.substr(2), path, ans);
            path = path.substr(0,path.size()-3);
        }
        
        if(s.size() > 2 && s[0] != '0' && s.substr(0,3) <= "255")
        {
            path+=s.substr(0,3) + '.';
            split(num+1, s.substr(3), path, ans);
            path = path.substr(0,path.size()-4);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string path = "";
        split(0,s,path,ans);
        return ans;
    }
};