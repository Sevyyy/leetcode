class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)
            return 0;
        int ans = 0;
        for(int i = 1;i < prices.size();i++)
        {
            if(prices[i] - prices[i-1] > 0)
                ans += prices[i] - prices[i-1];
        }
        return ans;
    }
};