/*
Problem no 1520
Platform : Leetcode
Problem name : Maximum Number of Non-Overlapping Substrings
Link : https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/description/
Approach : Kosaraju's Algorithm
Time Complexity : O(n)
Space Complexity : O(n)
*/
class Solution {
public:
    // Step 1: DFS for ordering (Kosaraju first pass)
    void dfs1(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) dfs1(it, adj, vis, st);
        }
        st.push(node);
    }

    // Step 2: DFS on reversed graph to get SCC
    void dfs2(int node, vector<vector<int>>& adjRev, vector<int>& vis, vector<int>& component) {
        vis[node] = 1;
        component.push_back(node);
        for (auto it : adjRev[node]) {
            if (!vis[it]) dfs2(it, adjRev, vis, component);
        }
    }

    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        // Step 1: first and last occurrence of each character
        vector<int> first(26, n), last(26, -1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = max(last[c], i);
        }

        // Step 2: Build graph
        vector<vector<int>> adj(26), adjRev(26);

        for (int c = 0; c < 26; c++) {
            if (first[c] == n) continue; // character not present

            for (int i = first[c]; i <= last[c]; i++) {
                int other = s[i] - 'a';
                if (other != c) {
                    adj[c].push_back(other);
                    adjRev[other].push_back(c);
                }
            }
        }

        // Step 3: Kosaraju - first DFS (ordering)
        vector<int> vis(26, 0);
        stack<int> st;
        for (int i = 0; i < 26; i++) {
            if (!vis[i] && first[i] != n) {
                dfs1(i, adj, vis, st);
            }
        }

        // Step 4: Kosaraju - second DFS (SCCs)
        fill(vis.begin(), vis.end(), 0);
        vector<vector<int>> sccs;

        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                vector<int> comp;
                dfs2(node, adjRev, vis, comp);
                sccs.push_back(comp);
            }
        }

        // Step 5: Convert each SCC to interval
        vector<pair<int,int>> intervals;

        for (auto &comp : sccs) {
            int l = n, r = -1;

            for (auto c : comp) {
                l = min(l, first[c]);
                r = max(r, last[c]);
            }

            // Validate interval
            bool valid = true;
            for (int i = l; i <= r; i++) {
                int c = s[i] - 'a';
                if (first[c] < l || last[c] > r) {
                    valid = false;
                    break;
                }
            }

            if (valid) intervals.push_back({l, r});
        }

        // Step 6: Sort by end (greedy for max non-overlapping)
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if (a.second == b.second) return a.first > b.first;
            return a.second < b.second;
        });

        // Step 7: Pick non-overlapping substrings
        vector<string> result;
        int prevEnd = -1;

        for (auto &it : intervals) {
            if (it.first > prevEnd) {
                result.push_back(s.substr(it.first, it.second - it.first + 1));
                prevEnd = it.second;
            }
        }

        return result;
    }
};