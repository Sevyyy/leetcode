class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        int m = matrix.size();
        if(m == 0)
            return 0;
        int n = matrix[0].size();
        for(int i = 0; i < m; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		if(matrix[i][j] == '1')
        		{
        			int a = i;
        			int b = j;
        			int minLength = n;
        			while(a < m && matrix[a][b] == '1')
        			{
        				int length = 0;
        				while(b < n && matrix[a][b] == '1')
        				{
        					length++;
        					b++;
        				}
        				minLength = min(minLength, length);
        				ans = max(ans, minLength * (a-i+1));
        				a++;
        				b = j;
        			}	
        		}
        	}
        }
        return ans;
    }
};