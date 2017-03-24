class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1)
            return 0;
        vector<int> left(n,0);
        vector<int> right(n,0);
        int buy = prices[0];
        int ans = 0;
        for(int i = 1;i < n;i++)
        {
            if(buy > prices[i])
                buy = prices[i];
            else
                ans = max(ans, prices[i] - buy);
            left[i] = ans;
        }
        buy = prices[n-1];
        ans = 0;
        for(int i = n-2;i >= 0;i--)
        {
            if(buy < prices[i])
                buy = prices[i];
            else
                ans = min(ans, prices[i] - buy);
            right[i] = ans;
        }
        ans = 0;
        for(int i = 0;i < n;i++)
        {
            if(ans < left[i]-right[i])
                ans = left[i]-right[i];
        }
        return ans;
    }
};