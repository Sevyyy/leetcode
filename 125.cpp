class Solution {
public:
    bool valid(char c)
    {
        if(c >= '0' && c <= '9')
            return true;
        else if(c >= 'a' && c <= 'z')
            return true;
        else if(c >= 'A' && c <= 'Z')
            return true;
        return false;
    }
    char lowercase(char c)
    {
        if(c >= 'A' && c <= 'Z')
            return c+'a'-'A';
        else
            return c;
    }
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right)
        {
            while(!valid(s[left]) && left < right)
                left++;
            while(!valid(s[right]) && left < right)
                right--;
            if(left < right && lowercase(s[left]) != lowercase(s[right]))
                return false;
            left++;
            right--;
        }
        return true;
    }
};