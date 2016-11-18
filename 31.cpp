class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() < 2)
            return;
        
        int i;
        for(i = nums.size() - 1; i > 0;--i)
            if(nums[i-1] < nums[i])
                break;
        
        if(i == 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        int k;
        for(k = nums.size() - 1; k > i-1;--k)
            if(nums[i-1] < nums[k])
                break;

        swap(nums[i-1], nums[k]);
        reverse(nums.begin() + i, nums.end());
        return;
    }
};