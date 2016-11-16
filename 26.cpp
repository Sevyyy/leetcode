class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        vector<int>::iterator itr = unique(nums.begin(), nums.end());
        return int(itr - nums.begin());
    }
};