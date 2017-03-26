class Solution {
public:
    bool adjacent(string a, string b)
    {
        int dif = 0;
        for(int i = 0;i < a.size();i++)
            if(a[i] != b[i])
                dif++;
        return dif==1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;
        wordList.push_back(beginWord);
        int n = wordList.size();
        int tar;
        for(int i = 0;i < n;i++)
            if(wordList[i] == endWord)
                tar = i;
        vector<vector<bool>> path(n, vector<bool>(n,false));
        for(int i = 0;i < n;i++)
        {
            for(int j = i+1;j < n;j++)
            {
                if(adjacent(wordList[i], wordList[j]))
                {
                    path[i][j] = true;
                    path[j][i] = true;
                }
            }
        }
        vector<bool> visit(n,false);
        visit[n-1] = true;
        queue<int> q;
        q.push(n-1);
        int ans = 2;
        while(!q.empty())
        {
            int len = q.size();
            while(len--)
            {
                int cur = q.front();
                q.pop();
                for(int i = 0;i < n;i++)
                {
                    if(path[cur][i] && !visit[i])
                    {
                        if(i == tar)
                            return ans;
                        visit[i] = true;
                        q.push(i);
                    }
                }
            }
            ans++;
        }
        return 0;
    }
};