class Solution {
public:
    int myAtoi(string str) {
        long ans = 0;
        bool flag = true;
        
        int index = 0;
        while(str[index] == ' ')
            index++;
        if(str[index] == '\0')
            return 0;
        if(str[index] == '+')
        {
            flag = true;
            index ++;
        }
        else if(str[index] == '-')
        {
            flag = false;
            index++;
        }
        else if((str[index]>='0') && (str[index]<='9'))
            flag = true;
        else
            return 0;
        while((str[index]>='0') && (str[index]<='9'))
        {
            int temp = str[index] - '0';
            ans = ans * 10 + temp;
            index++;
            if(ans > INT_MAX && flag)
                return INT_MAX;
            if(ans > INT_MAX && !flag)
                return INT_MIN;
        }
        if(flag)
            return int(ans);
        else
            return int(-ans);
    }
};