class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int sum = m + n;
        if(sum == 0)
            return 0;
        else if(sum == 1)
            return nums1.empty()?nums2.back():nums1.back();
        int mid = sum / 2;
        if(sum % 2)  //odd
        {
            int count = 0;
            while(count < mid)
            {
                if(!nums1.empty() && !nums2.empty())
                {
                    if(nums1.back() > nums2.back())
                        nums1.pop_back();
                    else
                        nums2.pop_back();
                    count++;
                }
                else if(nums1.empty())
                {
                    while(count < mid)
                    {
                        nums2.pop_back();
                        count++;
                    }
                    return nums2.back();
                }
                else if(nums2.empty())
                {
                    while(count < mid)
                    {
                        nums1.pop_back();
                        count++;
                    }
                    return nums1.back();
                }
            }
            return nums1.back() > nums2.back() ? nums1.back() : nums2.back();
        }
        else //even
        { 
            mid -= 1;
            int count = 0;
            while(count < mid)
            {
                if(!nums1.empty() && !nums2.empty())
                {
                    if(nums1.back() > nums2.back())
                        nums1.pop_back();
                    else
                        nums2.pop_back();
                    count++;
                }
                else if(nums1.empty())
                {
                    while(count < mid)
                    {
                        nums2.pop_back();
                        count++;
                    }
                    break;
                }
                else if(nums2.empty())
                {
                    while(count < mid)
                    {
                        nums1.pop_back();
                        count++;
                    }
                    break;
                }
            }
            int next1, next2;
            if(!nums1.empty() && !nums2.empty())
            {
                if(nums1.back() > nums2.back())
                {
                    next1 = nums1.back();
                    nums1.pop_back();
                }
                else
                {
                    next1 = nums2.back();
                    nums2.pop_back();
                }
            }
            else if(nums1.empty())
            {
                next1 = nums2.back();
                nums2.pop_back();
            }
            else if(nums2.empty())
            {
                next1 = nums1.back();
                nums1.pop_back();
            }
            if(!nums1.empty() && !nums2.empty())
            {
                if(nums1.back() > nums2.back())
                {
                    next2 = nums1.back();
                    nums1.pop_back();
                }
                else
                {
                    next2 = nums2.back();
                    nums2.pop_back();
                }
            }
            else if(nums1.empty())
            {
                next2 = nums2.back();
                nums2.pop_back();
            }
            else if(nums2.empty())
            {
                next2 = nums1.back();
                nums1.pop_back();
            }
            return (next1 + next2) / 2.0;
        }
    }
};