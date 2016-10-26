class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int max_mid1 = 0;
        int max_offset1 = 0;
        int max_mid2 = 0;
        int max_offset2 = 0;
        for(int mid = 0; mid < n; mid++)
        {
            for(int offset = 1; ; offset++)
            {
                if(mid - offset < 0 || mid + offset >= n || s[mid - offset] != s[mid + offset])
                {
                    if(offset - 1 > max_offset1)
                    {
                        max_mid1 = mid;
                        max_offset1 = offset - 1;
                    }
                    break;
                }
            }
            
            for(int offset = 1; ; offset++)
            {
                if(mid - offset + 1 < 0 || mid + offset >= n || s[mid - offset + 1] != s[mid + offset])
                {
                    if(offset - 1 > max_offset2)
                    {
                        max_mid2 = mid;
                        max_offset2 = offset - 1;
                    }
                    break;
                }
            }
        }
        if(max_offset1 >= max_offset2)
        {
            return s.substr(max_mid1 - max_offset1, max_offset1 * 2 + 1);
        }
        else
        {
            return s.substr(max_mid2 - max_offset2 + 1, max_offset2 * 2);
        }
    }
};