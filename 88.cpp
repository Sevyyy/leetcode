class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int loc1 = m-1;
        int loc2 = n-1;
        int loc = m+n-1;
        while(loc1 >= 0 && loc2 >= 0)
        {
            if(nums1[loc1] > nums2[loc2])
            {
                nums1[loc] = nums1[loc1];
                loc1--;
                loc--;
            }
            else
            {
                nums1[loc] = nums2[loc2];
                loc2--;
                loc--;
            }
        }
        while(loc2 >= 0)
        {
            nums1[loc] = nums2[loc2];
            loc2--;
            loc--;
        }
    }
};