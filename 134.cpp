class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int rest = 0;
        int debt = 0;
        int ans = 0;
        for(int i = 0;i < gas.size();i++)
        {
            rest += gas[i] - cost[i];
            if(rest < 0)
            {
                debt += rest;
                rest = 0;
                ans = (i+1)%gas.size();
            }
        }
        return rest+debt >= 0 ? ans : -1;
    }
};