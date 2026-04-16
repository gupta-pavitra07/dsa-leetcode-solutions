/*
Platform : GFG
Problem name : Number Of Islands (Online queries)
Link : https://www.geeksforgeeks.org/problems/number-of-islands/1
Approach : DSU
Time Complexity : O(k)
Space Complexity : O(n*m + k)
*/
// User function Template for C++
class DisjointSet
{
    public:
    vector<int>rank , parent, size;

    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        size.resize(n+1,1);

        for(int i = 0 ; i <= n ; i++)
        {
            parent[i] = i ;
            size[i] = 1;
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

    void Unionbysize(int u , int v)
    {
        int ul_u = findUpar(u);
        int ul_v = findUpar(v);

        if(ul_u == ul_v) return;

        if(size[ul_u] < size[ul_v])
        {
            parent[ul_u] = ul_v;
            size[ul_v] += size[ul_u];
        }
        else
        {
            parent[ul_v] = ul_u;
            size[ul_u] += size[ul_v];
        }
    }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) 
    {   
        //Declaration
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<int>ans;
        DisjointSet ds(n*m);
        int cnt = 0 ;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        
        for(auto it : operators)
        {
            int row = it[0];
            int col = it[1];
            if(vis[row][col] == 1 )
            {
                ans.push_back(cnt);
                continue;
            }
            vis[row][col] = 1 ;
            cnt++;
            
            for(int i = 0 ; i < 4 ; i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m)
                {
                    if(vis[nrow][ncol] == 1)
                    {
                        if(ds.findUpar(row*m + col ) != ds.findUpar(nrow*m + ncol))
                        {
                            cnt--;
                            ds.Unionbysize(row*m + col , nrow*m + ncol);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};