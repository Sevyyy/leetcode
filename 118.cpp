class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows == 0)
            return ans;
        vector<int> last(1,1);
        ans.push_back(last);
        for(int i = 2;i <= numRows;i++)
        {
            vector<int> v(1,1);
            for(int j = 1;j < i-1;j++)
            {
                v.push_back(last[j-1]+last[j]);
            }
            v.push_back(1);
            ans.push_back(v);
            last = v;
        }
        return ans;
    }
};