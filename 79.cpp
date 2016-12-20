class Solution {
public:
    bool DFS(vector<vector<char>>& board, string word, vector<vector<int>> &used, int m, int n, int row, int column)
    {
        if(word == "")
            return true;
        char cur = word[0];
        used[row][column] = 1;
        if(row > 0 && !used[row-1][column] && cur == board[row-1][column])
        {
            if(DFS(board, word.substr(1), used, m, n, row-1, column))
                return true;
        }
        if(row < m-1 && !used[row+1][column] && cur == board[row+1][column])
        {
            if(DFS(board, word.substr(1), used, m, n, row+1, column))
                return true;
        }
        if(column > 0 && !used[row][column-1] && cur == board[row][column-1])
        {
            if(DFS(board, word.substr(1), used, m, n, row, column-1))
                return true;
        }
        if(column < n-1 && !used[row][column+1] && cur == board[row][column+1])
        {
            if(DFS(board, word.substr(1), used, m, n, row, column+1))
                return true;
        }
        used[row][column] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size() == 0)
            return true;
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> used;
        vector<int> temp;
        for(int i = 0;i < n;i++)
            temp.push_back(0);
        for(int i = 0;i < m;i++)
            used.push_back(temp);
        if(!m || !n)
            return false;
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(board[i][j] == word[0])
                {
                    if(DFS(board, word.substr(1), used, m, n, i, j))
                        return true;
                }
            }
        }
        return false;
    }
};