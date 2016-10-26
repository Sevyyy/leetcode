class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        string *str = new string[numRows];
        for(int i = 0; i < numRows; i++)
            str[i] = "";
        int n = s.size();
        int row = 0;
        int inc = 1;
        for(int i = 0; i < n; i++)
        {
            str[row] += s[i];
            if(row == numRows - 1)
            {
                inc = -1;
            }
            else if(row == 0)
            {
                inc = 1;
            }
            row += inc;
        }
        string ans;
        for(int i = 0; i < numRows; i++)
        {
            ans += str[i];
        }
        return ans;
    }
};