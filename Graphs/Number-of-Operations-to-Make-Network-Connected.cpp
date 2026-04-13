/*
Problem no 1319
Platform : Leetcode
Problem name : Number of Operations to Make Network Connected
Link : https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
Approach : Disjoint Set Data Structure 
Time Complexity : O(E)
Space Complexity : O(n)
*/
class DisjointSet
{
    public:
    vector<int>rank , parent;

    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1,0);

        for(int i = 0 ; i <= n ; i++)
        {
            parent[i] = i ;
        }
    }

    int findUpar(int node)
    {
        if(node == parent[node]) return node;

        return parent[node] = findUpar(parent[node]);

    }

    void Unionbyrank(int u , int v)
    {
        int ul_u = findUpar(u);
        int ul_v = findUpar(v);

        if(ul_u == ul_v) return;

        if(rank[ul_u] < rank[ul_v]) parent[ul_u] = ul_v;
        else if(rank[ul_u] > rank[ul_v]) parent[ul_v] = ul_u;
        else
        {
            parent[ul_v] = ul_u;
            rank[ul_u]++;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        DisjointSet ds(n);
        int extraedges = 0;
        for(auto it : connections)
        {
            int u = it[0];
            int v = it[1];
            if(ds.findUpar(u) != ds.findUpar(v))
            {
                ds.Unionbyrank(u,v);
            }
            else if (ds.findUpar(u) == ds.findUpar(v))
            {
                extraedges++;
            }
        }
        int components = 0 ;
        for(int i = 0 ; i < n ; i++)
        {
            if(ds.parent[i] == i) components++;
        }

        int ans = components-1;
        if(extraedges >= ans) return ans;
        return -1;
    }
};