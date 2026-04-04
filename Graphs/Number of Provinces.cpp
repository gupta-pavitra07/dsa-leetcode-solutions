//problem 547
class Solution {
public:

    void dfs(int node ,vector<int> adj[] , vector<int>&vis , int n )
    {
        vis[node]++;

        for(int it : adj[node])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis,n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size();

        vector<int> adj[n];

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n  ; j++)
            {
                if(isConnected[i][j] == 1 && i!=j) adj[i].push_back(j);
            }
        }

        vector<int> vis(n,0);
        int noofprovinces = 0 ;
        for(int i = 0 ; i<n ; i++)
        {
            if(!vis[i])
            {
                noofprovinces++;
                dfs(i,adj,vis,n);
            }
        }
        return noofprovinces;

    }
};