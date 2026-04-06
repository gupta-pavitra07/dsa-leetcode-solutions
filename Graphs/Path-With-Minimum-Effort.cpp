/*
Problem no 1631
Platform : Leetcode
Problem name : Path With Minimum Effort
Link : https://leetcode.com/problems/path-with-minimum-effort/description/
Approach : Dijkstras Algoruithm
Time Complexity : O(m X n X 4 X log(m X n))
Space Complexity : O(m X n)
*/
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int m = heights.size();
        int n = heights[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));

        q.push({0,{0,0}});
        dist[0][0] = 0 ;

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!q.empty())
        {
            int diff = q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            q.pop();

            if(row == m-1 && col == n-1) return diff;

            for(int i =0 ; i < 4 ; i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >=0 && nrow < m && ncol >=0 && ncol < n)
                {
                    int neweffort = max(abs(heights[row][col] - heights[nrow][ncol]),diff);
                    if(neweffort < dist[nrow][ncol])
                    {
                        dist[nrow][ncol] = neweffort;
                        q.push({neweffort,{nrow,ncol}});
                    }
                }
            }
        }
        return 0;
    }
};