class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(!m)
            return false;
        int n = matrix[0].size();
        if(!n)
            return false;
        int left = 0;
        int right = m*n - 1;
        int mid = (left + right) / 2;
        while(left <= right)
        {
            int i = mid / n;
            int j = mid % n;
            if(target == matrix[i][j])
            {
                return true;
            }
            else if(target > matrix[i][j])
            {
                left = mid + 1;
                mid = (left + right) / 2;
            }
            else
            {
                right = mid - 1;
                mid = (left + right) / 2;
            }
        }
        return false;
    }
};