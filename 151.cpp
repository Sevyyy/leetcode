class Solution {
public:
    void reverseWords(string &s) {
        int n = s.size();
        for(int i = 0;i < n/2;i++)
        {
            char temp = s[i];
            s[i] = s[n-i-1];
            s[n-i-1] = temp;
        }
        int head = 0;
        int tail = 0;
        while(head < n)
        {
            while(s[head] == ' ' && head < n)
                head++;
            tail = head;
            while(s[tail] != ' ' && tail < n)
                tail++;
            if(head < n)
            {
                for(int i = head;i < (tail+head)/2;i++)
                {
                    char temp = s[i];
                    s[i] = s[tail-(i-head)-1];
                    s[tail-(i-head)-1] = temp;
                }
            }
            head = tail;
        }
        int index = 0;
        int point = 0;
        bool flag = true;
        int i = 0;
        while(s[i] == ' ' && i < n)
        {
            i++;
        }
        for(;i < n;i++)
        {
            if(s[i] == ' ')
            {
                while(s[i] == ' ' && i < n)
                {
                    i++;
                }
                s[index] = ' ';
                index++;
            }
            if(i < n)
            {
                s[index] = s[i];
                index++;
            }
        }
        if(s[index-1] == ' ')
            s = s.substr(0,index-1 >= 0? index-1 : 0);
        else
            s = s.substr(0,index-1 >= 0? index : 0);
    }
};