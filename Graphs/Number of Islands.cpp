//Problem 200
class Solution {
public:
    void dfs(int i , int j , vector<vector<int>>&vis , vector<vector<char>>&grid , int drow[] , int dcol[])
    {
        vis[i][j] = 1 ;

        for(int k = 0 ; k < 4 ; k++)
        {
            int nrow = i + drow[k];
            int ncol = j + dcol[k];

            if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && !vis[nrow][ncol] && grid[nrow][ncol] == '1' )
            {
                dfs(nrow,ncol,vis,grid,drow,dcol);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        int islands = 0 ;

        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n; j++)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    islands++;
                    dfs(i,j,vis,grid,drow,dcol);
                }
            }
        }
        return islands;
    }
};