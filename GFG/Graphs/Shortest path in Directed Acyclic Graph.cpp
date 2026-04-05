// Platform: GFG
// Problem: Shortest Path in Undirected Graph
// Link: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
// Approach: Topological Sort (for DAG)

// Key Idea:
// - Convert graph into adjacency list
// - Perform Topological Sort using DFS
// - Initialize distance array with INF
// - Process nodes in topo order and relax edges

// Time Complexity: O(V + E)
// Space Complexity: O(V + E)
class Solution {
  public:
    void toposort(int node ,vector<int>&vis,stack<int>&st, vector<pair<int,int>>adj[] )
    {
        vis[node] = 1 ;
        
        for(auto it : adj[node])
        {
            int adjnode = it.first; 
            if(!vis[adjnode])
            {
                toposort(adjnode,vis,st,adj);
            }
        }
        st.push(node);
    }
    vector<int> shortestPath(int v, int e, vector<vector<int>>& edges) 
    {
        vector<pair<int,int>>adj[v];
        for(int i = 0 ; i<e ; i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        stack<int>st;
        vector<int>vis(v,0);
        
        for(int i = 0 ; i<v ; i++)
        {
            if(!vis[i])
            {
                toposort(i,vis,st,adj);
            }
        }
        
        vector<int>dist(v,INT_MAX);
        dist[0] = 0;
        
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            
            for(auto it : adj[node])
            {
                int adjn = it.first;
                if(dist[node] != INT_MAX && dist[adjn] > dist[node] + it.second)
                {
                    dist[adjn] = dist[node]+it.second;
                }
            }
        }
        for(int i = 0; i < v; i++)
        {
            if(dist[i] == INT_MAX)
                dist[i] = -1;
        }
        return dist;
    }
};