class Solution {
public:
    string intToString(long long n){
        if(n == 0)
            return "0";
        string ret = "";
        while(n){
            ret = (char)(n%10+'0') + ret;
            n /= 10;
        }
        return ret;
    }
    string fractionToDecimal(int numerator1, int denominator1) {
        if(numerator1 == 0)
            return "0";
        long long numerator = numerator1;
        long long denominator = denominator1;
        bool flag = false;
        if(numerator > 0 && denominator < 0 || numerator < 0 && denominator > 0){
            flag = true;
        }
        numerator = abs(numerator);
        denominator = abs(denominator);
        long long zheng = abs(numerator/denominator);
        string ret = intToString(zheng);
        long long rest = numerator - zheng*denominator;
        
        if(rest == 0){
            return flag?"-"+ret:ret;
        }
        ret = ret + ".";
        string ans = "";
        map<long long, int> m;
        int index = 0;
        while(1){
            if(m.find(rest) == m.end()){
                m[rest] = index;
                rest = rest*10;
                int z = rest / denominator;
                ans += (char)(z+'0');
                rest = rest - z*denominator;
                index++;
                if(rest == 0){
                    ans = ret + ans;
                    if(flag)
                        return "-"+ans;
                    else
                        return ans;
                }
            }else{
                int pos = m[rest];
                ans = ans.substr(0,pos) + "(" + ans.substr(pos) + ")";
                ans = ret + ans;
                if(flag)
                    return "-"+ans;
                else
                    return ans;
            }
        }
        return "0";
    }
};