//Problem 207
class Solution {
public:
    bool dfs(int node ,vector<int>&vis,vector<int>&pathvis,vector<int>adj[] )
    {
        vis[node] = 1 ;
        pathvis[node] = 1 ;

        for(auto adjnode : adj[node])
        {
            if(!vis[adjnode])
            {
                if(dfs(adjnode,vis,pathvis,adj) == true) return true;
            }
            else if(pathvis[adjnode])
            {
                return true;
            }
        }
        pathvis[node] = 0;
        return false;
    }
    bool canFinish(int numcourses, vector<vector<int>>& prerequisites) 
    {
        int n = numcourses;
        
        vector<int>adj[n];

        for(int i = 0 ; i < prerequisites.size() ; i++)
        {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            adj[b].push_back(a);
        }

        vector<int>vis(n,0);
        vector<int>pathvis(n,0);

        for(int i = 0 ; i<n ; i++)
        {
            if(!vis[i])
            {
                if(dfs(i,vis,pathvis,adj) == true) return false;
            }
        }
        return true;

    }

};