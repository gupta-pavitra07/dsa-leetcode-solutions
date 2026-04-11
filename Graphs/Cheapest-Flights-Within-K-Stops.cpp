/*
Problem no 787
Platform : Leetcode
Problem name : Cheapest Flights Within K Stops
Link : https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
Approach : BFS + edgeweight relaxation 
Time Complexity : O(E .k)
Space Complexity : O(V+E+V.k)
*/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<pair<int,int>>adj[n];

        for(int i = 0 ; i < flights.size() ; i++)
        {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }

        vector<int>price(n,INT_MAX);
        //{stops,{price,node}}
        queue<pair<int,pair<int,int>>>pq;

        price[src] = 0 ;
        pq.push({0,{0,src}});


        while(!pq.empty())
        {
            int stops = pq.front().first;
            int p = pq.front().second.first;
            int node = pq.front().second.second;
            pq.pop();
            
            if(stops > k) continue;


            for(auto it : adj[node])
            {
                int adjnode = it.first;
                int edgep = it.second;

                if(edgep + p < price[adjnode])
                {
                    price[adjnode] = edgep + p ;
                    pq.push({stops+1,{price[adjnode],adjnode}});
                }
            }
        }
        if(price[dst] == INT_MAX) return -1;
        return price[dst];
    }
};