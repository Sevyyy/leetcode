class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        if(!n)
            return ans;
        int subs = pow(2,n);
        for(int i = 0;i < subs;i++)
        {
            int base = i;
            int e = n-1;
            vector<int> temp;
            while(base)
            {
                if(base % 2)
                {
                    temp.push_back(nums[e]);
                }
                base /= 2;
                e--;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};