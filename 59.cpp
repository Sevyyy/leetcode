class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans;
        for(int i = 0;i < n;i++)
        {
            vector<int> temp;
            ans.push_back(temp);
            for(int j = 0;j < n;j++)
            {
                ans[i].push_back(0);
            }
        }
        int u = 0;
        int d = n-1;
        int l = 0;
        int r = n-1;
        int t = 1;
        while(1)
        {
            if(u <= d && l <= r)
            {
                for(int i = l;i <= r;i++)
                {
                    ans[u][i] = t;
                    t++;
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
                    ans[i][r] = t;
                    t++;
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
                    ans[d][i] = t;
                    t++;
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
                    ans[i][l] = t;
                    t++;
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