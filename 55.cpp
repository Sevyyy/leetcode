class Solution {
public:
    bool canJump(vector<int>& nums) {
        int pos = 0;
        int n = nums.size();
        if(n <= 1)
        {
            return true;
        }
        while(pos < n)
        {
            int index = pos;
            int dis = 0;
            for(int i = 1;i <= nums[pos] && pos + i <= n;i++)
            {
                if(pos + i == n-1)
                {
                    return true;
                }
                if(dis < nums[pos+i] + i)
                {
                    dis = nums[pos+i] + i;
                    index = pos + i;
                }
            }
            pos = index;
            if(nums[pos] == 0)
            {
                return false;
            }
        }
        return true;
    }
};