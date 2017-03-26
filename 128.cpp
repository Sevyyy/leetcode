class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, bool> visit;
        for(int i = 0;i < nums.size();i++)
            visit[nums[i]] = false;
        for(int i = 0;i < nums.size();i++)
        {
            if(!visit[nums[i]])
            {
                int len = 1;
                int left = nums[i]-1;
                int right = nums[i]+1;
                while(visit.find(left) != visit.end() && !visit[left] && left >= INT_MIN)
                {
                    visit[left] = true;
                    len++;
                    left--;
                }
                while(visit.find(right) != visit.end() && !visit[right] && right <= INT_MAX)
                {
                    visit[right] = true;
                    len++;
                    right++;
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};