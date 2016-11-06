class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.size() == 0)
            return s.size() == 0;
        else if(s.size() == 0)
        {
            if(p.size() > 1 && p[1] == '*' && isMatch(s, p.substr(2)))
                return true;
            return false;
        }
        else if(p.size() > 1 && p[1] == '*')
        {
            if(isMatch(s, p.substr(2)))
                return true;
            else if(s[0] == p[0] || p[0] == '.')
            {
                return isMatch(s.substr(1), p);
            }
            else
                return false;
        }
        else
        {
            return ((s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1)));
        }
    }
};