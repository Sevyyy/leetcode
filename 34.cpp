class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        if(nums.size() == 0)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int a = 0;
        int b = nums.size();
        int mid = (a+b)/2;
        int start = -1;
        int end;
        while(a < b)
        {
            if(nums[mid] == target)
            {
                if(mid == 0 || nums[mid-1] < target)
                {
                    start = mid;
                    break;
                }
                else if(nums[mid-1] == target)
                {
                    b = mid;
                    mid = (a+b)/2;
                }
            }
            else if(nums[mid] < target)
            {
                a = mid + 1;
                mid = (a+b)/2;
            }
            else if(nums[mid] > target)
            {
                b = mid;
                mid = (a+b)/2;
            }
        }
        
        if(start == -1)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        
        a = start+1;
        b = nums.size();
        mid = (a+b)/2;
        end = start;
        while(a < b)
        {
            if(nums[mid] == target)
            {
                if(mid == nums.size()-1 || nums[mid+1] > target)
                {
                    end = mid;
                    break;
                }
                else if(nums[mid+1] == target)
                {
                    a = mid+1;
                    mid = (a+b)/2;
                }
            }
            /*
            else if(nums[mid] < target)
            {
                a = mid + 1;
                mid = (a+b)/2;
            }
            */
            else if(nums[mid] > target)
            {
                b = mid;
                mid = (a+b)/2;
            }
        }
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};