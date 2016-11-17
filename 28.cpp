class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if(m > n)
            return -1;
        if(m == 0)
            return 0;
        int *next = new int[m+1];
        next[0] = next[1] = 0;
        int j = 0;
        
        for(int i = 1;i < m;i++)
        {
            while(j > 0 && needle[i] != needle[j])
            {
                j = next[j];
            }
            if(needle[i] == needle[j])
            {
                j++;
            }
            next[i+1] = j;
        }
        
        j = 0;
        for (int i = 0; i < n; i++) 
        {
    		while (j > 0 && haystack[i] != needle[j])
    			j = next[j];
    		if (haystack[i] == needle[j])
    			j++;
    		if (j == m) 
    		{
    			return i-j+1;
    		}
        }
        return -1;
    }
};