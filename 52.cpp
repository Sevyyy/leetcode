class Solution {
public:
    void DFS(vector<vector<string>> &ans, vector<string> &temp, int* used1, int* used2, int* used3, int n)
    {
        if(temp.size() == n)
        {
            ans.push_back(temp);
            return;
        }
        else
        {
            int r = temp.size();
            for(int i = 0;i < n;i++)
            {
                if(!used1[i] && !used2[r+i] && !used3[i-r+n-1])
                {
                    used1[i] = 1;
                    used2[r+i] = 1;
                    used3[i-r+n-1] = 1;
                    string row = "";
                    for(int j = 0;j<n;j++)
                        row = row+'.';
                    row[i] = 'Q';
                    temp.push_back(row);
                    DFS(ans, temp, used1, used2, used3, n);
                    used1[i] = 0;
                    used2[r+i] = 0;
                    used3[i-r+n-1] = 0;
                    temp.pop_back();
                }
            }
        }
        return;
    }
    int totalNQueens(int n) {
        vector<vector<string>> ans;
        if(!n)
            return 0;
        int *used1 = new int[n];
        int *used2 = new int[2*n-1];
        int *used3 = new int[2*n-1];
        for(int i = 0;i < n;i++)
            used1[i] = 0;
        for(int i = 0;i < 2*n-1;i++)
            used2[i] = 0;
        for(int i = 0;i < 2*n-1;i++)
            used3[i] = 0;
        vector<string> temp;
        DFS(ans, temp, used1, used2, used3, n);
        return ans.size();
    }
};