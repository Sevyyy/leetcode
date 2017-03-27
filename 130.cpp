class Solution {
public:
    void helper(vector<vector<char>>& board, int i, int j)
    {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int>> q;
        pair<int, int> p(i,j);
        q.push(p);
        board[i][j] = 'Q';
        while(!q.empty())
        {
            p = q.front();
            q.pop();
            int x, y;
            //up
            x = p.first;
            y = p.second-1;
            if(y > 0 && board[x][y] == 'O')
            {
                board[x][y] = 'Q';
                q.push(pair<int, int>(x,y));
            }
            //down
            x = p.first;
            y = p.second+1;
            if(y < n && board[x][y] == 'O')
            {
                board[x][y] = 'Q';
                q.push(pair<int, int>(x,y));
            }
            //left
            x = p.first-1;
            y = p.second;
            if(x > 0 && board[x][y] == 'O')
            {
                board[x][y] = 'Q';
                q.push(pair<int, int>(x,y));
            }
            //right
            x = p.first+1;
            y = p.second;
            if(x < m && board[x][y] == 'O')
            {
                board[x][y] = 'Q';
                q.push(pair<int, int>(x,y));
            }
        }
        
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m == 0)
            return;
        int n = board[0].size();
        for(int i = 0;i < m;i++)
        {
            if(board[i][0] == 'O')
                helper(board,i,0);
            if(board[i][n-1] == 'O')
                helper(board,i,n-1);
        }
        for(int i = 0;i < n;i++)
        {
            if(board[0][i] == 'O')
                helper(board,0,i);
            if(board[m-1][i] == 'O')
                helper(board,m-1,i);
        }
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == 'Q')
                    board[i][j] = 'O';
            }
        }
        return;
    }
};