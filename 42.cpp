class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 2)
            return 0;
        int left = 0;
        int right = height.size()-1;
        int sum = 0;
        while(height[left] == 0)
            left++;
        while(height[right] == 0)
            right--;
        int h = min(height[left], height[right]);
        while(left < right)
        {
            h = max(h, min(height[left], height[right]));
            if(height[left] <= height[right])
            {
                left++;
                if(height[left] <= h)
                {
                    sum += h - height[left];
                }
            }
            else
            {
                right--;
                if(height[right] <= h)
                {
                    sum += h - height[right];
                }
            }
        }
        return sum;
    }
};