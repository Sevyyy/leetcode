class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n = strs.size();
        if(n == 0)
            return ans;
        map<string, vector<string>> m;
        for(int i = 0;i < n;i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            m[temp].push_back(strs[i]);
        }
        for(map<string, vector<string>>::iterator it = m.begin();it != m.end();it++)
        {
            ans.push_back(it->second);
        }
        return ans;
    }
};