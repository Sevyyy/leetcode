class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        string ans = "";
        int n1 = num1.size();
        int n2 = num2.size();
        int *sum = new int[n1 + n2];
        for(int i = 0;i < n1+n2;i++)
            sum[i] = 0;
        for(int i = 0;i < n1;i++)
        {
            for(int j = 0;j < n2;j++)
            {
                sum[i+j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        int ex = 0;
        for(int i = 0;i < n1+n2;i++)
        {
            sum[i] += ex;
            ex = sum[i] / 10;
            sum[i] = sum[i] % 10;
        }
        int max = n1 + n2 - 1;
        while(sum[max] == 0)
            max--;
        for(int i = 0;i <= max;i++)
        {
            ans = char(48 + sum[i]) + ans;
        }
        return ans;
    }
};