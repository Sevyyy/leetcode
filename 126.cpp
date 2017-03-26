class Solution {
private:
    void isConnected(vector<string>&connect, unordered_set<string>& wordList, const string &current, const string & end, unordered_set<string>&visit)
    {
        connect.clear();
        string cur = current;
        for (int i = 0; i < cur.size(); i++)
        {
            char t = cur[i];
            for (char c = 'a'; c < 'z'; c++)
            {
                if (c == t)
                {
                    continue;
                }
                cur[i] = c;
                if ((cur == end || wordList.find(cur) != wordList.end()) && (visit.find(cur) == visit.end()))
                {
                    connect.push_back(cur);
                }

            }
            cur[i] = t;
        }
    }// isConnect求当前节点相连多所有节点

    //BFS
    void bfs(map<string,vector<string>>&preNode, unordered_set<string>&wordList, const string &beginWord, const string& endWord)
    {
        queue<string>q;
        unordered_set<string>visit;//是否访问
        visit.insert(beginWord);
        vector<string>connect;
        q.push(beginWord);
        while (!q.empty())
        {
            int len = q.size();
            vector<string> tmpVisit;
            while (len--)
            {
                string current = q.front();
                q.pop();
                isConnected(connect, wordList, current, endWord, visit);
                for (int i = 0; i < connect.size(); i++)
                {
                    if (visit.find(connect[i]) == visit.end())//未被访问
                    {
                        if (preNode[connect[i]].empty())//这个判断语句为了防止图中所说情况
                        {
                            tmpVisit.push_back(connect[i]);
                            q.push(connect[i]);
                        }

                        preNode[connect[i]].push_back(current);
                    }
                }
            }//每一层
            for (int j = 0; j < tmpVisit.size(); j++)//每一层结束记录访问节点
            {
                visit.insert(tmpVisit[j]);
            }
            if (visit.find(endWord) != visit.end())
                return;
        }
    }

    void dfs(const string &beginWord, const string &t, vector<string>tmp, map<string,vector<string>>&preNode, vector<vector<string>>&result)
    {
        if (t == beginWord)
        {
            tmp.push_back(beginWord);
            vector<string>tmpres(tmp.rbegin(), tmp.rend());
            result.push_back(tmpres);
            return;
        }
        tmp.push_back(t);
        for (int i = 0; i < preNode[t].size(); i++)
            dfs(beginWord, preNode[t][i], tmp, preNode, result);
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        unordered_set<string> word_list;
        for(int i = 0;i < wordList.size();i++)
            word_list.insert(wordList[i]);
        vector<vector<string>>result;
        if(word_list.find(endWord) == word_list.end())
            return result;
        map<string, vector<string>>preNode;

        bfs(preNode, word_list, beginWord, endWord);
        vector<string>tmp;
        dfs(beginWord, endWord, tmp, preNode, result);
        return result;
    }
};