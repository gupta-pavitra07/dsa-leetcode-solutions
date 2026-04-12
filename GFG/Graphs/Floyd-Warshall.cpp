/*
Platform : GFG
Problem name : Floyd Warshall
Link : https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
Approach : Floyd Warshall Algorithm
Time Complexity : O(n^3)
Space Complexity : O(n^2)
*/
class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) 
    {
        int n = dist.size();
        
        //floyd warshall
        for(int k = 0 ; k < n ; k ++ )
        {
            for(int i = 0 ; i < n ; i++)
            {
                for(int j = 0 ; j < n ; j++)
                {
                    if(dist[i][k] != 1e8 && dist[k][j] != 1e8)
                    {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }
};