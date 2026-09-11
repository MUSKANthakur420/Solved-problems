class Solution {
public:
    void dfs(int node, int parent, vector<int>& dist, vector<int>& subtree,
             vector<int> adj[]) {
        subtree[node] = 1;
        for (auto it : adj[node]) {
            if (it != parent) {
                dfs(it, node, dist, subtree, adj);
                subtree[node] += subtree[it];
                dist[node] += dist[it] + subtree[it];
            }
        }
    }
    void final(int node, int parent, vector<int>& dist, vector<int>& subtree,
               vector<int> adj[], int n) {
        for (auto it : adj[node]) {
            if (parent != it) {
                dist[it] = dist[node] - 2 * subtree[it] + n;
                final(it, node, dist, subtree, adj, n);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n + 1];
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> dist(n, 0);
        vector<int> subtree(n, 0);
        dfs(0, -1, dist, subtree, adj);
        final(0, -1, dist, subtree, adj, n);
        return dist;
    }
};