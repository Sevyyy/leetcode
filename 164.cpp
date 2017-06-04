class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2){
            return 0;
        }
        int big = INT_MIN;
        int small = INT_MAX;
        for(int i = 0;i < n;i++){
            if(nums[i] > big)
                big = nums[i];
            if(nums[i] < small)
                small = nums[i];
        }
        double gap = (big-small)*1.0 / (n-1);
        vector<int> maxv(n-1, INT_MIN);
        vector<int> minv(n-1, INT_MAX);
        for(int i = 0;i < n;i++){
            if(nums[i] != big){
                int id = int((nums[i]-small)/gap);
                minv[id] = min(minv[id], nums[i]);
                maxv[id] = max(maxv[id], nums[i]);
            }
        }
        int ret = 0;
        int last = maxv[0];
        for(int i = 0;i < n-2;i++){
            if(minv[i+1] != INT_MAX){
                ret = max(ret, minv[i+1]-last);
                last = maxv[i+1];
            }
        }
        ret = max(ret, big-last);
        return ret;
    }
};