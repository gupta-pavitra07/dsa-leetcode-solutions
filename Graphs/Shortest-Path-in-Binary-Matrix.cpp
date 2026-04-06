/*
Problem no 1091
Platform : Leetcode
Problem name : Shortest Path in Binary Matrix
Link : https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
Approach : BFS + Dijkstras Algoruithm
Time Complexity : n2
Space Complexity : n2
*/
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        if(n == 1) return 1;

        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));

        q.push({1,{0,0}});
        dist[0][0] = 1 ;

        int drow[] = {-1,-1,0,1,1,1,0,-1};
        int dcol[] = {0,1,1,1,0,-1,-1,-1};

        while(!q.empty())
        {
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            for(int i = 0 ; i < 8 ; i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow>=0 && nrow < n && ncol>=0 && ncol < n && grid[nrow][ncol] == 0)
                {
                    if(dis + 1 < dist[nrow][ncol])
                    {
                        dist[nrow][ncol] = dis + 1 ;
                        if(nrow == n-1 && ncol == n-1) return dis + 1;
                        q.push({dis+1,{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};