class Solution {
public:
    string countAndSay(int n) {
        string origin = "1";
        string ans = "1";
        while(--n)
        {
            ans = "";
            int index = -1;
            int s = origin.size();
            for(int i = 0;i < s;i++)
            {
                int count = 1;
                char cur = origin[i];
                while(i++ < s && origin[i] == cur)
                {
                    count++;
                }
                i--;
                ans += count + '0';
                ans += cur;
            }
            origin = ans;
        }
        return ans;
    }
};