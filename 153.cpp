class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int mid = (left+right)/2;
        while(left < right-1){
            if(nums[mid] > nums[right]){
                left = mid;
                mid = (left+right)/2;
            }
            else if(nums[mid] < nums[left]){
                right = mid;
                mid = (left+right)/2;
            }
            else{
                return nums[0];
            }
        }
        return min(nums[(mid+1)%n],nums[(mid%n)]);
    }
};