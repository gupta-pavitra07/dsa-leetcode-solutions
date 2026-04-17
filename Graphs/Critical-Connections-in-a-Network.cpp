/*
Problem no 1192
Platform : Leetcode
Problem name : Critical Connections in a Network
Link : https://leetcode.com/problems/accounts-merge/description/
Approach : DFS
Time Complexity : O(N+2E)
Space Complexity : O(N+2E + 3N)
*/
class Solution {
public:
    int timer = 1;
    void dfs(int node , int parent , vector<int>&vis , int tin[] , int low[] ,vector<int>adj[],vector<vector<int>>&bridges)
    {
        vis[node] = 1 ;
        tin[node] = low[node] = timer;
        timer++;

        for(auto it : adj[node])
        {
            if(it == parent) continue ;
            if(!vis[it])
            {
                dfs(it,node,vis,tin,low,adj,bridges);
                low[node] = min(low[node] , low[it]);
                
                //can this be a bridge??
                if(low[it] > tin[node])
                {
                    bridges.push_back({it,node});
                }
            }
            else
            {
                low[node] = min(low[node],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        vector<int>adj[n];

        for(auto it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int>vis(n,0);
        int tin[n];
        int low[n];
        vector<vector<int>>bridges;
        dfs(0,-1,vis,tin,low,adj,bridges);
        return bridges;
    }
};