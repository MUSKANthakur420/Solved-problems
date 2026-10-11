
class Solution {
public:
    long long dfs(int node, int parent, int k, int state,
                  vector<pair<int, int>> adj[], vector<vector<long long>>& dp) {

        if (dp[node][state] != -1)
            return dp[node][state];

        vector<long long> value;
        long long sum = 0;

        for (auto it : adj[node]) {
            if (it.first == parent)
                continue;

            long long notake = dfs(it.first, node, k, 0, adj, dp);
            long long take = it.second + dfs(it.first, node, k, 1, adj, dp);

            sum += notake;

            if (take > notake)
                value.push_back(take - notake);
        }

        sort(value.rbegin(), value.rend());

        int slots = k - state;

        for (int i = 0; i < min(slots, (int)value.size()); i++)
            sum += value[i];

        return dp[node][state] = sum;
    }

    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        int n = edges.size() + 1;

        vector<pair<int, int>> adj[n];
        for (auto it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<vector<long long>> dp(n, vector<long long>(2, -1));

        return dfs(0, -1, k, 0, adj, dp);
    }
};
