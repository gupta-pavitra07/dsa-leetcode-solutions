/*
Problem no 721
Platform : Leetcode
Problem name : Accounts Merge
Link : https://leetcode.com/problems/accounts-merge/description/
Approach : DSU
Time Complexity : O(N⋅K⋅logK)
Space Complexity : O(N⋅K)
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
    {
        int n = accounts.size();

        unordered_map<string,int>mppMailNode;
        DisjointSet ds(n);

        //merge mails which are common to same people (assuming index of accounts as nodes)
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 1 ; j < accounts[i].size() ; j++)
            {
                string mail = accounts[i][j];
                if(mppMailNode.find(mail) == mppMailNode.end())
                {
                    mppMailNode[mail] = i ;
                }
                else
                {
                    ds.Unionbysize(i,mppMailNode[mail]);
                }
            }
        }

        vector<string>mergedmail[n];

        for(auto it : mppMailNode)
        {
            string mail = it.first;
            int i = ds.findUpar(it.second);

            mergedmail[i].push_back(mail);
        }

        vector<vector<string>>ans;

        for(int i = 0 ; i < n ; i++)
        {
            if(mergedmail[i].size() == 0 ) continue ;
            sort(mergedmail[i].begin(),mergedmail[i].end());

            vector<string> temp ;
            string name = accounts[i][0];
            temp.push_back(name);
            for(auto it : mergedmail[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }  
        return ans;
    }
};