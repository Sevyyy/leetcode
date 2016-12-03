class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int n = s.size();
        int i = n-1;
        while(s[i] == ' ')
            i--;
        for(;i >= 0;i--)
        {
            if(s[i]!= ' ')
            {
                ans++;
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};