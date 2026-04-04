//Problem 785
class Solution {
public:
    bool dfs(int node , int col , vector<int>&color , vector<vector<int>>& graph)
    {
        color[node] = col ;

        for(auto adjnode : graph[node])
        {
            if(color[adjnode] == -1 )
            {
                if(dfs(adjnode,!col,color,graph) == false) return false;
            }
            else
            {
                if(color[adjnode] == col)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int>color(n,-1);

        for(int i = 0 ; i < n ; i++)
        {
            if(color[i] == -1)
            {
                if(dfs(i,0,color,graph) == false) return false;
            }
        }
        return true;
    }
};