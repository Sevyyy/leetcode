class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)
            return 0;
        int ans = 0;
        int buy = prices[0];
        for(int i = 1;i < prices.size();i++)
        {
            if(prices[i] < buy)
                buy = prices[i];
            else
                ans = max(ans, prices[i] - buy);
        }
        return ans;
    }
};