class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0)
            return 0;
        int start = 0;
        int end = 1;
        int length = 1;
        while(end < n)
        {
            bool flag = true;
            for(int i = start; i < end; i++)
            {
                if(s[end] == s[i])
                {
                    length = end - start > length ? end - start : length;
                    start = i + 1;
                    flag = false;
                    break;
                }
            }
            
            if(flag == true)
                length = end - start + 1 > length ? end - start + 1 : length;
            
            end ++;
        }
        return length;
    }
};