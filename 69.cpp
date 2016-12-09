class Solution {
public:
    int mySqrt(int x) {
        long long xx = x;
        long long ans = 0;
        while(ans*ans <= xx)
        {
            ans++;
        }
        return ans - 1;
    }
};