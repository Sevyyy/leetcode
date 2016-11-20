class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
        {
            if(target <= nums[0])
                return 0;
            else
                return 1;
        }
        int a = 0;
        int b = nums.size();
        int mid = (a+b)/2;
        while(a < b)
        {
            if(target == nums[mid])
                return mid;
            else if(target < nums[mid])
            {
                b = mid;
                mid = (a+b)/2;
            }
            else if(target > nums[mid] && target < nums[mid+1])
            {
                return mid + 1;
            }
            else if(target >= nums[mid+1])
            {
                a = mid+1;
                mid = (a+b)/2;
            }
        }
        if(mid == 0)
            return 0;
        return nums.size();
    }
};