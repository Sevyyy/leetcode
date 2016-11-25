class Solution {
public:
    bool isMatch(string s, string p) {
        if(s.size() == 0 && p.size() == 0)
        {
            return true;
        }
        else if(p.size() == 0)
        {
            return false;
        }
        else if(p[0] == '*')
        {
            int next = 1;
            while(p[next] == '*')
                next++;
            for(int i = 0;i <= s.size();i++)
            {
                if(isMatch(s.substr(i), p.substr(next)))
                {
                    return true;
                }
            }
        }
        else if(p[0] == '?')
        {
            if(s.size() > 0)
            {
                return isMatch(s.substr(1), p.substr(1));
            }
            else
            {
                return false;
            }
        }
        else if(s.size() > 0 && p[0] == s[0])
        {
            return isMatch(s.substr(1), p.substr(1));
        }
        else
        {
            return false;
        }
        return false;
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        string star = "!";
        string backup = "!";

        while(s.size() > 0)
        {
            if(p[0] == '*')
            {
                backup = s;
                p = p.substr(1);
                star = p;
            }
            else if(p[0] == '?' || p[0] == s[0])
            {
                s = s.substr(1);
                p = p.substr(1);
            }
            else if(star != "!")
            {
                p = star;
                backup = backup.substr(1);
                s = backup;
            }
            else
            {
                break;
            }
        }
        while(p[0] == '*')
        {
            p = p.substr(1);
        }
        
        return ((s.size() == 0) && (p.size() == 0));
    }
};

//up is my tle code

//down is AC code