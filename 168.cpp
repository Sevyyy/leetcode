class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        while(n > 0){
            int temp = n % 26;
            if(temp == 0){
                ans = "Z" + ans;
                n/=26;
                n-=1;
            }
            else{
                ans = (char)(temp+'A'-1) + ans;
                n /= 26;
            }
        }
        return ans;
    }
};