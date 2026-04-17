/*
Problem no 778
Platform : Leetcode
Problem name : Swim in Rising Water
Link : https://leetcode.com/problems/swim-in-rising-water/description/
Approach : Dijkstras Algorithm
Time Complexity : O(n2logn)
Space Complexity : O(n2)
*/
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        //{cost,{i,j}}
        priority_queue<
                    pair<int,pair<int,int>>,
                    vector<pair<int,pair<int,int>>>,
                    greater<pair<int,pair<int,int>>>
                    >pq;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        vector<vector<int>>dist(n,vector<int>(n,1e8));

        pq.push({grid[0][0],{0,0}});
        dist[0][0] = grid[0][0];

        while(!pq.empty())
        {
            auto it = pq.top();
            int cost = it.first;
            int row = it.second.first;
            int col = it.second.second;
            pq.pop();
            if(cost > dist[row][col]) continue;
            if(row == n-1 && col == n-1) return cost;

            for(int k = 0 ; k < 4 ; k++)
            {
                int nrow = row + drow[k];
                int ncol = col + dcol[k];

                if(nrow >= 0 && ncol >=0 && nrow < n && ncol < n)
                {
                    int edgecost = grid[nrow][ncol];
                    int newcost = max(cost,edgecost);
                    if(newcost < dist[nrow][ncol])
                    {
                        dist[nrow][ncol] = newcost;
                        pq.push({newcost,{nrow,ncol}});
                    }
                }
            }
        }
        return -1;

    }
};