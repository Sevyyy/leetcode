class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 0;
        int n = nums.size();
        if(n < 3)
            return ans;
        sort(nums.begin(), nums.end());
        int min = INT_MAX;
        for(int i = 0;i < n; i++)
        {
            int a = i + 1;
            int b = n - 1;
            while(a < b)
            {
                int dis = nums[i] + nums[a] + nums[b] - target;
                if(dis > 0)
                {
                    b--;
                    if(abs(dis) < min)
                    {
                        min = abs(dis);
                        ans = dis + target;
                    }
                }
                else if(dis < 0)
                {
                    a++;
                    if(abs(dis) < min)
                    {
                        min = abs(dis);
                        ans = dis + target;
                    }
                }
                else
                {
                    return target;
                }
            }
        }
        return ans;
    }
};