//PROBLEM 802
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int v = graph.size();
        vector<int> graphrev[v];
        vector<int> indegree(v,0);
        vector<int>res;
        queue<int>q;

        for(int i = 0 ; i < v ; i++)
        {
            //i -> adjnode
            for(auto adjnode : graph[i])
            {
                //adjnode -> i
                graphrev[adjnode].push_back(i);
                indegree[i]++;
            }
        }

        for(int i = 0 ; i < v ; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(auto adj : graphrev[node])
            {
                indegree[adj]--;
                if(indegree[adj] == 0)
                {
                    q.push(adj);
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};