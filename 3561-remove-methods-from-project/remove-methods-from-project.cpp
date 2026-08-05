class Solution {
public:
    bool flag = true;
    void dfs(int node, vector<int>& vis, vector<int> adj[]) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj);
            }
        }
    }
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<int> adj[n + 1];
        for (auto it : invocations) {
            adj[it[0]].push_back(it[1]);
        }
        vector<int> ans;
        vector<int> vis(n, 0);
        dfs(k, vis, adj);
        for (auto it : invocations) {
            if (!vis[it[0]] && vis[it[1]]) {
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                ans.push_back(i);
        }
        return ans;
    }
};