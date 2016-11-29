class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1.0;
        else if(n < 0)
        {
            if(n == INT_MIN)
                return 1.0/(myPow(x,INT_MAX) * x);
            return 1.0/myPow(x,-n);
        }
        else if(n == 1)
            return x;
        else 
        {
            double temp = myPow(x,n/2);
            if(n % 2 == 0)
                return temp*temp;
            else
                return temp*temp*x;
        }
    }
};