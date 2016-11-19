class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        if(nums.size() == 1)
        {
            if(target == nums[0])
                return 0;
            else
                return -1;
        }
        int offset = 0;
        int a = 0;
        int b = nums.size()-1;
        int mid = (a+b)/2;
        while(a < b)
        {
            if(nums[mid] > nums[mid+1])
            {
                offset = mid+1;
                break;
            }
            else
            {
                if(nums[mid] < nums[0])
                {
                    b = mid;
                    mid = (a+b)/2;
                }
                else
                {
                    a = mid+1;
                    mid = (a+b)/2;
                }
            }
        }
        int ans = -1;
        a = 0;
        b = nums.size();
        mid = (a+b)/2;
        while(a < b)
        {
            int temp = nums[(mid+offset) % nums.size()];
            if(target == temp)
            {
                ans = mid;
                break;
            }
            else if(target < temp)
            {
                b = mid;
                mid = (a+b)/2;
            }
            else
            {
                a=mid + 1;
                mid = (a+b)/2;
            }
        }
        if(ans == -1)
            return -1;
        return (ans+offset) % nums.size();
    }
};