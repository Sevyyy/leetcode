class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> row;
        vector<int> column;
        int m = matrix.size();
        if(!m)
            return;
        int n = matrix[0].size();
        for(int i = 0;i < m;i++)
            row.push_back(0);
        for(int i = 0;i < n;i++)
            column.push_back(0);
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(matrix[i][j] == 0)
                {
                    row[i] = 1;
                    column[j] = 1;
                }
            }
        }
        for(int i = 0;i < m;i++)
        {
            if(row[i])
            {
                for(int j = 0;j < n;j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int i = 0;i < n;i++)
        {
            if(column[i])
            {
                for(int j = 0;j < m;j++)
                {
                    matrix[j][i] = 0;
                }
            }
        }
        return;
    }
};