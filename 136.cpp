class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int helper = 0;
        for(int i = 0;i < nums.size();i++)
            helper ^= nums[i];
        return helper;
    }
};