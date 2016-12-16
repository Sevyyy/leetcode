class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        vector<int> count;
        count.push_back(0);
        count.push_back(0);
        count.push_back(0);
        for(int i = 0;i < n;i++)
        {
            count[nums[i]]++;
        }
        nums.clear();
        for(int num = 0;num < 3;num++)
        {
            for(int i = 0;i < count[num];i++)
            {
                nums.push_back(num);
            }
        }
    }
};