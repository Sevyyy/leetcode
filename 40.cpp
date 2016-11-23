class Solution {
public:
    void dfs(int sum, vector<vector<int>> &ans, vector<int>& candidates, vector<int> &temp, int cur, int target)
    {
        if(sum > target)
            return;
        else if(sum == target)
        {
            ans.push_back(temp);
            return;
        }
        else
        {
            for(int i = cur; i < candidates.size(); i++)
            {
                while(i > cur && candidates[i] == candidates[i-1])
                {
                    if(i < candidates.size() - 1)
                        i++;
                    else
                        return;
                }
                sum += candidates[i];
                temp.push_back(candidates[i]);
                dfs(sum, ans, candidates, temp, i+1, target);
                temp.pop_back();
                sum -= candidates[i];
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        dfs(sum, ans, candidates, temp, 0, target);
        return ans;
    }
};