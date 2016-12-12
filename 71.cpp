class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        int start = 0;
        stack<string> s;
        if(path[n-1] != '/')
            path += "/";
        n = path.size();
        for(int i = 1;i < n;i++)
        {
            if(path[i] == '/')
            {
                string token = path.substr(start+1,i-start-1);
                if(token == "..")
                {
                    if(!s.empty())
                    {
                        s.pop();
                    }
                }
                else if(token == "." || token == "")
                {
                    ;
                }
                else
                {
                    s.push(token);
                }
                start = i;
            }
        }
        if(s.empty())
            return "/";
        else
        {
            string ans = "";
            while(!s.empty())
            {
                ans = "/" + s.top() + ans;
                s.pop();
            }
            if(ans == "")
                ans = "/";
            return ans;
        }
    }
};