class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        for(int i = 2;i < nums.size();i++)
        {
            if(nums[i] == nums[i-2])
            {
                nums.erase(nums.begin() + i);
                i--;
            }
        }
        return nums.size();
    }
};