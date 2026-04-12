/*
Problem no 1334
Platform : Leetcode
Problem name : Find the City With the Smallest Number of Neighbors at a Threshold Distance
Link : https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/
Approach : Floyd Warshell Algorithm
Time Complexity : O(n^3)
Space Complexity : O(n^2)
*/
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        vector<vector<int>>mat(n,vector<int>(n,1e9));

        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            mat[u][v] = w ;
            mat[v][u] = w ;
        }
        for(int i = 0 ; i < n ; i ++)
        {
            for(int j = 0 ; j < n ; j ++)
            {
                if( i == j) mat[i][j] = 0 ;
            }
        }
        

        //floyd warshell

        for(int k = 0 ; k < n ; k++)
        {
            for(int i = 0 ; i < n ; i ++)
            {
                for(int j = 0 ; j < n ; j++)
                {
                    if(mat[i][k] != 1e9 && mat[k][j] != 1e9)
                    {
                        mat[i][j] = min(mat[i][j] , mat[i][k] + mat[k][j]);
                    }
                }
            }
        }

        vector<int>no_of_neighbours(n,0);

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if( i!=j && mat[i][j] <= distanceThreshold) no_of_neighbours[i]++;
            }
        }

        int neigh = INT_MAX;
        int node = -1;
        for(int i = 0 ; i < n ; i++)
        {
            if(no_of_neighbours[i] <= neigh)
            {
                neigh = no_of_neighbours[i];
                node = i ;
            }
        }
        return node;
    }
};