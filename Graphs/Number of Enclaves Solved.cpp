//Problem 1020
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        queue<pair<int,int>>q;
        
        //first row and last row
        for(int j = 0 ; j < m ; j++)
        {
            if(grid[0][j] == 1)
            {
                q.push({0,j});
                vis[0][j] = 1;
            }
            if(grid[n-1][j] == 1)
            {
                q.push({n-1,j});
                vis[n-1][j] = 1;
            }
        }
        //first col and last col
        for(int i = 0 ; i < n ; i ++)
        {
            if(grid[i][0] == 1)
            {
                q.push({i,0});
                vis[i][0] = 1 ;
            }
            if(grid[i][m-1] == 1)
            {
                q.push({i,m-1});
                vis[i][m-1] = 1;
            }
        }
        
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int k = 0 ; k < 4 ; k++)
            {
                int nrow = r+drow[k];
                int ncol = c+dcol[k];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
                {
                    vis[nrow][ncol] = 1 ;
                    q.push({nrow,ncol});
                }
            }
        }
        int count = 0 ;
        
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                if(grid[i][j] == 1 && vis[i][j] == 0)
                {
                    count++;
                }
            }
        }
        return count;
        
    }
};