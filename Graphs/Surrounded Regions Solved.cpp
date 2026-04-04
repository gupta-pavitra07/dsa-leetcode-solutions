//Problem 130
class Solution {
public:

    void dfs(int i , int j , vector<vector<int>>&vis , vector<vector<char>>& board , int drow[] , int dcol[] )
    {
        vis[i][j] = 1 ;

        for(int k = 0 ; k < 4 ; k++)
        {
            int nrow = i + drow[k];
            int ncol = j + dcol[k];

            if(nrow >= 0 && nrow < board.size() && ncol >=0 && ncol < board[0].size() && vis[nrow][ncol]==0 && board[nrow][ncol] == 'O')
            {
                dfs(nrow,ncol,vis,board,drow,dcol);
            }
        }
    }

    void solve(vector<vector<char>>& board) 
    {
        int m = board.size();
        int n = board[0].size();

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        vector<vector<int>>vis(m , vector<int>(n,0));
        //first row and last row and loop till no of columns (important)
        for(int j = 0 ; j < n ; j++)
        {
            if(!vis[0][j] && board[0][j] == 'O')
            {
                dfs(0,j,vis,board,drow,dcol);
            }
            if(!vis[m-1][j] && board[m-1][j] == 'O')
            {
                dfs(m-1,j,vis,board,drow,dcol);
            }
        }
        //first column and last column and loop till number of rows (important)
        for(int j = 0 ; j < m ; j++)
        {
            if(!vis[j][0] && board[j][0] == 'O')
            {
                dfs(j,0,vis,board,drow,dcol);
            }
            if(!vis[j][n-1] && board[j][n-1] == 'O')
            {
                dfs(j,n-1,vis,board,drow,dcol);
            }
        }

        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(board[i][j] == 'O' && vis[i][j] == 0)
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};