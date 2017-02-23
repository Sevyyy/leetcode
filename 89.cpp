class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        if(n == 0)
            return ans;
        ans.push_back(1);
        for(int q = 1;q < n;q++)
        {
            int m = ans.size();
            int temp = pow(2,q);
            for(int i = m-1; i>=0; i--)
            {
                ans.push_back(ans[i]+temp);
            }
        }
        return ans;
    }
};