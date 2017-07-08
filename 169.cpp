class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        int n = nums.size();
        if(n<=2){
            return nums[0];
        }
        for(auto each:nums){
            if(m.find(each) != m.end()){
                m[each] += 1;
                if(m[each] > n/2){
                    return each;
                }
            }
            else{
                m[each] = 1;
            }
        }
    }
};