class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        if(m == 0)
            return ans;
        int n = matrix[0].size();
        int u = 0;
        int d = m-1;
        int l = 0;
        int r = n-1;
        while(1)
        {
            if(u <= d && l <= r)
            {
                for(int i = l;i <= r;i++)
                {
                    ans.push_back(matrix[u][i]);
                }
                u++;
            }
            else
            {
                break;
            }
            if(u <= d && l <= r)
            {
                for(int i = u;i <= d;i++)
                {
                    ans.push_back(matrix[i][r]);
                }
                r--;
            }
            else
            {
                break;
            }
            if(u <= d && l <= r)
            {
                for(int i = r;i >= l;i--)
                {
                    ans.push_back(matrix[d][i]);
                }
                d--;
            }
            else
            {
                break;
            }
            if(u <= d && l <= r)
            {
                for(int i = d;i >= u;i--)
                {
                    ans.push_back(matrix[i][l]);
                }
                l++;
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};