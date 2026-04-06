// Platform: GFG
// Problem: Shortest Path in Undirected Graph
// Link: https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
// Approach: Dijkstras Algorithm 
// Time Complexity : O(ElogV)

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) 
    {
        vector<pair<int,int>>adj[n+1];
        
        for(int i = 0 ; i < m  ; i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n+1,INT_MAX);
        vector<int>parent(n+1);
        for(int i = 0 ; i < n+1 ; i++)
        {
            parent[i] = i;
        }
        vector<int>result;
        
        dist[1] = 0 ;
        parent[1] = 1 ;
        
        pq.push({0,1});
        
        while(!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(dis > dist[node]) continue ;
            
            for(auto it : adj[node])
            {
                int adjnode = it.first;
                int edgew = it.second;
                if(edgew + dis < dist[adjnode])
                {
                    dist[adjnode] = edgew + dis;
                    parent[adjnode] = node;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        
        if(dist[n] == INT_MAX) return {-1};
        
        result.push_back(dist[n]);
        int node = n ;
        while( parent[node] != node)
        {
            result.push_back(node);
            node = parent[node];
        }
        result.push_back(1);
        
        reverse(result.begin()+1,result.end());
        return result;

    }
};