// Platform: GFG
// Problem: Dijkstras Algorithm
// Link: https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
// Approach: Using Priority Queue
//Time Complexity : O(Elog V)
//Space Complexity : O(V+E)
class Solution {
  public:
    vector<int> dijkstra(int v, vector<vector<int>> &edges, int src) 
    {
        vector<pair<int,int>>adj[v];
        for(int i = 0 ; i < edges.size() ; i ++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<int>dist(v,INT_MAX);
        dist[src] = 0 ;
        pq.push({0,src});
        
        while(!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(dis > dist[node]) continue;
            
            for(auto it : adj[node])
            {
                int edgeweight = it.second;
                int adjnode = it.first;
                
                if(edgeweight + dis < dist[adjnode])
                {
                    dist[adjnode] = edgeweight + dis ;
                    pq.push({edgeweight+dis,adjnode});
                }
            }
        }
        return dist;
    }
};