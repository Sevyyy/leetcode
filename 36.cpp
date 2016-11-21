class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0;i < 9;i++)
        {
            set<int> s;
            for(int j = 0;j < 9;j++)
            {
                if(board[i][j] != '.')
                {
                    if(s.find(board[i][j]) != s.end())
                    {
                        return false;
                    }
                    else
                    {
                        s.insert(board[i][j]);
                    }
                }
            }
        }
        
        for(int i = 0;i < 9;i++)
        {
            set<int> s;
            for(int j = 0;j < 9;j++)
            {
                if(board[j][i] != '.')
                {
                    if(s.find(board[j][i]) != s.end())
                    {
                        return false;
                    }
                    else
                    {
                        s.insert(board[j][i]);
                    }
                }
            }
        }
        
        for(int r = 0;r < 9;r+=3)
        {
            for(int c = 0;c < 9;c+=3)
            {
                set<int> s;
                for(int i = 0;i < 3;i++)
                {
                    for(int j = 0;j < 3;j++)
                    {
                        if(board[r+i][c+j] != '.')
                        {
                            if(board[r+i][c+j] == 3)
                                return false;
                            if(s.find(board[r+i][c+j]) != s.end())
                            {
                                return false;
                            }
                            else
                            {
                                s.insert(board[r+i][c+j]);
                            }
                        }
                    }
                }
            }
        }
        
        return true;
    }
};