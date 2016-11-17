class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0)
            return 0;
        if(divisor == 0)
            return INT_MAX;
        
        int flag = 1;
        if(dividend <0)
            flag = 0 - flag;
        if(divisor < 0)
            flag = 0 - flag;
        
        long long ans = 0;
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long base = 1;
        while(a > b)
        {
            b = b << 1;
            base = base << 1;
        }
        long long bb = abs((long long)divisor);
        while(a >= bb)
        {
            while(a >= b)
            {
                a = a - b;
                ans = ans + base;
            }
            b = b >> 1;
            base = base >> 1;
        }
        if(flag < 0)
            ans = 0 - ans;
        if(ans > INT_MAX || ans < INT_MIN)
            return INT_MAX;
        return ans;
    }
};