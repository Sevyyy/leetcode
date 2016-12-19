class Solution {
public:
    void DFS(vector<vector<int>> &ans, vector<int> temp, int *used, int k, int n)
    {
        if(temp.size() == k)
        {
            ans.push_back(temp);
            return;
        }
        int start = 1;
        if(!temp.empty())
            start = temp.back();
        for(int i = start;i <= n;i++)
        {
            if(!used[i])
            {
                used[i] = 1;
                temp.push_back(i);
                DFS(ans, temp, used, k, n);
                used[i] = 0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        int *used = new int[n+1];
        for(int i = 0;i < n+1;i++)
            used[i] = 0;
        vector<int> temp;
        DFS(ans, temp, used, k, n);
        delete[] used;
        return ans;
    }
};