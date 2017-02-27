class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n == 0)
            return 0;
        if(s[0] == '0')
            return 0;
        int cur = 1;
        int last = 1;
        for(int i = 1;i < n; i++)
        {
            int temp = cur;
            if(s[i] == '0')
            {
                if(s[i-1] == '1' || s[i-1] == '2')
                    cur = last;
                else
                    return 0;
            }
            else if(s[i-1] == '1' || s[i-1] == '2' && s[i] <= '6')
            {
                cur = cur + last;
            }
            last = temp;
        }
        return cur;
    }
};