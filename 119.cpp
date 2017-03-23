class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> last(1,1);
        if(rowIndex == 0)
            return last;
        for(int i = 2;i <= rowIndex+1;i++)
        {
            vector<int> v(1,1);
            for(int j = 1;j < i-1;j++)
            {
                v.push_back(last[j-1]+last[j]);
            }
            v.push_back(1);
            last = v;
        }
        return last;
    }
};