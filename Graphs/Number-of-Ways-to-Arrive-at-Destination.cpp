/*
Problem no 1976
Platform : Leetcode
Problem name : Number of Ways to Arrive at Destination
Link : https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/
Approach : Dijkstras Alogorithm
Time Complexity : O(E log V)
Space Complexity : O(V+E)
*/

class Solution {
public:

    int countPaths(int n, vector<vector<int>>& roads) 
    {
        const int MOD = 1e9 + 7;
        vector<pair<int,int>>adj[n];
        for(int i = 0 ; i < roads.size() ; i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }

        vector<long long>times(n,LLONG_MAX);
        times[0] = 0 ;
        
        vector<int>ways(n,0);
        ways[0] = 1;

        //{time,node}
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});

        while(!pq.empty())
        {
            int node = pq.top().second;
            long long t = pq.top().first;

            pq.pop();
            if(t > times[node]) continue;

            for(auto it : adj[node])
            {
                int adjnode = it.first;
                int edget = it.second;
                long long newTime = edget + t;
                if(newTime < times[adjnode])
                {
                    ways[adjnode] = ways[node];
                    times[adjnode] = newTime;
                    pq.push({times[adjnode],adjnode});
                }
                else if (newTime == times[adjnode])
                {
                    ways[adjnode] = (ways[node] + ways[adjnode]) % MOD;
                }
            }
        }
        return ways[n-1] % MOD;
    }
};