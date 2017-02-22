class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size())
            return false;
        if(s1 == s2)
            return true;
        int a[26] = {0};
        for(int i = 0; i < s1.size(); i++)\
        {
            a[s1[i] - 'a'] ++;
            a[s2[i] - 'a'] --;
        }
        for(int i = 0;i < 26; i++)
        {
            if(a[i] != 0)
                return false;
        }
        for(int i = 1;i < s1.size();i++)
        {
            string t11 = s1.substr(0,i);
            string t12 = s1.substr(i);
            string t21 = s2.substr(0,i);
            string t22 = s2.substr(i);
            string t23 = s2.substr(s1.size()-i);
            string t24 = s2.substr(0,s1.size()-i);
            if(isScramble(t11,t21) && isScramble(t12,t22) || isScramble(t11,t23) && isScramble(t12,t24))
                return true;
        }
        return false;
    }
};