class Solution {
public:
    int titleToNumber(string s) {
        if(s == ""){
            return 0;
        }
        int ans = 0;
        int n = s.size()-1;
        int base = 1;
        while(n>=0){
            char temp = s[n];
            
            ans = ans+base*(int)(temp-'A'+1);
            n--;
            base*=26;
        }
        return ans;
    }
};