class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int n = 1;
        while(x / n >= 10)
            n *= 10;
        while(x)
        {
            int a = x % 10;
            int b = x / n;
            if(a != b)
                return false;
            x = (x % n) / 10;
            n /= 100;
        }
        return true;
    }
};