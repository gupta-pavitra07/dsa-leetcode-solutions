/*
Problem no 827
Platform : Leetcode
Problem name : Making A Large Island
Link : https://leetcode.com/problems/making-a-large-island/description/
Approach : DSU
Time Complexity : O(n2)
Space Complexity : O(n2)
*/
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
    int largestIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        DisjointSet ds(n * n);
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        //connecting all the 1s into components
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(grid[i][j] == 0) continue ;
                for(int k = 0 ; k < 4 ; k++)
                {
                    int nrow = i + drow[k];
                    int ncol = j + dcol[k];

                    if(nrow >= 0 && nrow < n && ncol >=0 && ncol < n && grid[nrow][ncol] == 1)
                    {
                        ds.Unionbysize(i * n + j , nrow * n + ncol);
                    }
                }
            }
        }

        //finding the largest components
        int maxsize = 0 ;
        for(int row = 0 ; row < n ; row++)
        {
            for(int col = 0 ; col < n ; col++)
            {
                unordered_set<int>st;
                if(grid[row][col] == 1) continue;

                for(int i = 0 ; i < 4 ; i++)
                {
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];
                    
                    if(nrow >= 0 && nrow < n && ncol >=0 && ncol < n && grid[nrow][ncol] == 1)
                    {
                        st.insert(ds.findUpar(nrow * n + ncol));
                    }
                }
                int totalSize = 0;
                for(auto it : st)
                {
                    totalSize += ds.size[it];
                }
                maxsize = max(totalSize+1 , maxsize);
            }
        }
        //if grid has all 1's

        for(int cellNo = 0 ; cellNo < n*n ; cellNo++)
        {
            maxsize = max(maxsize , ds.size[ds.findUpar(cellNo)]);
        }
        return maxsize;
    }
};