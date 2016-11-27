class Solution {
public:
    int jump(vector<int>& nums) {
        int pos = 0;
        int n = nums.size();
        if(n <= 1)
        {
            return 0;
        }
        int ans = 0;
        while(pos < n)
        {
            int index = pos;
            int dis = 0;
            for(int i = 1;i <= nums[pos] && pos + i <= n;i++)
            {
                if(pos + i == n-1)
                {
                    return ans+1;
                }
                if(dis < nums[pos+i] + i)
                {
                    dis = nums[pos+i] + i;
                    index = pos + i;
                }
            }
            pos = index;
            ans++;
        }
        return ans;
    }
};