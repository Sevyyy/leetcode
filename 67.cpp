class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size();
        int n = b.size();
        if(m > n)
        {
            string temp = a;
            a = b;
            b = temp;
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        m = a.size(); // small
        n = b.size();
        int index = 0;
        int flag = 0;
        string ans = "";
        while(index < m)
        {
            int temp = (a[index] - '0') + (b[index] - '0') + flag;
            if(temp == 0)
            {
                ans += "0";
                flag = 0;
            }
            else if(temp == 1)
            {
                ans += "1";
                flag = 0;
            }
            else if(temp == 2)
            {
                ans += "0";
                flag = 1;
            }
            else if(temp == 3)
            {
                ans += "1";
                flag = 1;
            }
            index ++;
        }
        while(index < n)
        {
            int temp = (b[index] - '0') + flag;
            if(temp == 0)
            {
                ans += "0";
                flag = 0;
            }
            else if(temp == 1)
            {
                ans += "1";
                flag = 0;
            }
            else if(temp == 2)
            {
                ans += "0";
                flag = 1;
            }
            index ++;
        }
        if(flag == 1)
        {
            ans += "1";
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};