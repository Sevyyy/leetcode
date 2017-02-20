class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        heights.push_back(-1);
        stack<int> s;
        for(int i = 0;i < heights.size(); i++)
        {
        	while(!s.empty() && heights[s.top()] >= heights[i])
        	{
        		int temp = heights[s.top()];
        		s.pop();
        		int sq = temp * (s.empty()? i : (i - s.top() - 1));
        		ans = max(ans, sq);
        	}
        	s.push(i);
        }
        return ans;
    }
};