class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        vector<int> num;
        for(int i = 1;i <= n;i++)
        {
            num.push_back(i);
        }
        int jie = 1;
        for(int i = 1;i <= n-1;i++)
        {
            jie *= i;
        }
        k--;
        while(n > 0)
        {
            int index = k / jie;
            k = k % jie;
            ans += char('0' + num[index]);
            num.erase(num.begin() + index);
            if(n > 1)
                jie = jie / (n-1);
            n--;
        }
        return ans;
    }
};