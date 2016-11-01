class Solution {
public:
    int reverse(int x) {
        if(overflow(x))
            return 0;
        int ans = 0;
        while(x)
        {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
private:
    bool overflow(int x)
    {
        if (x / 1000000000 == 0) 
        {  
            return false;  
        } 
        else if (x == INT_MIN)   
        {  
            return true;  
        }   
        x = abs(x);  
        for (int cmp = 463847412; cmp != 0; cmp/=10, x/=10)  
        {  
            if ( x%10 > cmp%10 )  
            {  
                return true;  
            } 
            else if (x%10 < cmp%10)  
            {  
                return false;  
            }  
        }  
          
        return false;  
    }
};