// Platform: GFG
// Problem: Shortest Path in Undirected Graph (Unit Distance)
// Link: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
// Approach: BFS using queue + distance array
// Time: O(V + E)
// Space: O(V+E)
class Solution {
  public:
    vector<int> shortestPath(int v, vector<vector<int>> &edges, int src) 
    {

        vector<int>adj[v];
        
        for(int i = 0 ; i< edges.size() ; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int>dist(v,1e9);
        queue<int>q;
        vector<int>res(v,-1);
        
        q.push(src);
        dist[src] = 0 ;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto adjnode : adj[node])
            {
                int dis = dist[node] + 1;
                if(dis < dist[adjnode])
                {   
                    dist[adjnode] = dis;
                    q.push(adjnode);
                }
            }
        }
        for(int i = 0 ; i < v ; i ++)
        {
            if(dist[i]!=1e9)
            {
                res[i] = dist[i];
            }
        }
        return res;
    }
};