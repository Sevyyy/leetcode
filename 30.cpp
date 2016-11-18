class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if(s == "" || words.size() == 0)
            return ans;
            
        int n = s.size();
        int m = words[0].size();
        
        map<string, int> word_map;
        for(int i = 0;i < words.size();i++)
        {
            word_map[words[i]] = word_map[words[i]] + 1;
        }
        map<string, int> back_up = word_map;
        
        for(int i = 0;i < n-m*words.size() + 1;i++)
        {
            int count = 0;
            word_map = back_up;
            for(int j = 0; j < words.size();j++)
            {
                string cur = s.substr(i+j*m, m);
                if(word_map.find(cur) == word_map.end())
                {
                    break;
                }
                else
                {
                    if(word_map[cur] > 0)
                    {
                        word_map[cur]--;
                        count++;
                    }
                    else
                    {
                        break;
                    }
                }
                if(count == words.size())
                {
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};