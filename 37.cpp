class Solution {
public:
    bool isok(vector<vector<char>> board, int pos)
    {
        int row = pos / 9;
        int column = pos % 9;
        char v = board[row][column];
        for(int i = 0;i < 9;i++)
        {
            if(i != column && board[row][i] == v)
                return false;
            if(i != row && board[i][column] == v)
                return false;
            int a = row/3*3 + i/3;
            int b = column/3*3 + i%3;
            if(a*9+b != pos && board[a][b] == v)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board, int pos)
    {
        if(pos == 81)
            return true;
        if(board[pos/9][pos%9] == '.')
        {
            for(int i = 0;i < 9;i++)
            {
                board[pos/9][pos%9] = i+'1';
                if(isok(board,pos) && solve(board,pos+1))
                    return true;
                board[pos/9][pos%9] = '.';
            }
        }
        else if(solve(board, pos+1))
            return true;
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        bool f = solve(board, 0);
    }
};