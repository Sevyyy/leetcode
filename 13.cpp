class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int index = 0;
        int ans = 0;
        while(index < n)
        {
            if(s[index] == 'M')
            {
                ans += 1000;
                index ++;
            }
            else if(s[index] == 'D')
            {
                ans += 500;
                index++;
            }
            else if(s[index] == 'C')
            {
                if(index + 1 < n && s[index+1] == 'D')
                {
                    ans += 400;
                    index += 2;
                }
                else if(index + 1 < n && s[index+1] == 'M')
                {
                    ans += 900;
                    index += 2;
                }
                else
                {
                    ans += 100;
                    index ++;
                }
            }
            else if(s[index] == 'L')
            {
                ans += 50;
                index ++;
            }
            else if(s[index] == 'X')
            {
                if(index + 1 < n && s[index+1] == 'L')
                {
                    ans += 40;
                    index += 2;
                }
                else if(index + 1 < n && s[index+1] == 'C')
                {
                    ans += 90;
                    index += 2;
                }
                else
                {
                    ans += 10;
                    index ++;
                }
            }
            else if(s[index] == 'V')
            {
                ans += 5;
                index ++;
            }
            else if(s[index] == 'I')
            {
                if(index + 1 < n && s[index+1] == 'V')
                {
                    ans += 4;
                    index += 2;
                }
                else if(index + 1 < n && s[index+1] == 'X')
                {
                    ans += 9;
                    index += 2;
                }
                else
                {
                    ans += 1;
                    index ++;
                }
            }
        }
        return ans;
    }
};