/*
Problem no 743
Platform : Leetcode
Problem name : Network Delay Time
Link : https://leetcode.com/problems/network-delay-time/description/
Approach : Dijkstras Algorithm
Time Complexity : O(E log V)
Space Complexity : O(V+E)
*/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<pair<int,int>>adj[n+1];

        for(int i = 0 ; i < times.size(); i++)
        {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }

        //{time,node}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        vector<int>timetaken(n+1,INT_MAX);


        q.push({0,k});
        timetaken[k] = 0;

        int ans = 0 ;
        while(!q.empty())
        {
            int t = q.top().first;
            int node = q.top().second;
            q.pop();

            for(auto it : adj[node])
            {
                int adjnode = it.first;
                int edget = it.second;

                if(t + edget < timetaken[adjnode])
                {
                    timetaken[adjnode] = t + edget;
                    q.push({timetaken[adjnode],adjnode});
                }
            }
        }

        for(int i = 1 ; i <= n ; i ++)
        {
            if(timetaken[i] == INT_MAX) return -1;
            ans = max(ans,timetaken[i]);
        }
        return ans;
    }
};