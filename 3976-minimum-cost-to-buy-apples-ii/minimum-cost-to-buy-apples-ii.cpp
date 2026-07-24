class Solution {
public:
    int bfs(int n, int node, vector<pair<int, pair<int, int>>> adj[],
            vector<int>& prices) {
        vector<long long> dist(n, 1e18);
        dist[node] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;
        pq.push({0, node});
        while (!pq.empty()) {
            int newnode = pq.top().second;
            long long int cost = pq.top().first;
            pq.pop();
            if (dist[newnode] < cost)
                continue;
            for (auto it : adj[newnode]) {
                int adjnode = it.first;
                int c = it.second.first;
                if (cost + c < dist[adjnode]) {
                    dist[adjnode] = c + cost;
                    pq.push({dist[adjnode], adjnode});
                }
            }
        }
        vector<long long> revdist(n, 1e18);
        revdist[node] = 0;
        pq = priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                            greater<pair<long long, int>>>();
        pq.push({0, node});
        while (!pq.empty()) {
            int newnode = pq.top().second;
            long long int cost = pq.top().first;
            pq.pop();
            if (revdist[newnode] < cost)
                continue;
            for (auto it : adj[newnode]) {
                int adjnode = it.first;
                int c = it.second.first;
                int tax = it.second.second;
                long long sum = 1LL * c * tax + cost;
                if (sum < revdist[adjnode]) {
                    revdist[adjnode] = sum;
                    pq.push({revdist[adjnode], adjnode});
                }
            }
        }
        long long int mini = 1e18;
        for (int i = 0; i < n; i++) {
            mini = min(mini, dist[i] + revdist[i] + prices[i] * 1LL);
        }
        return mini;
    }
    vector<int> minCost(int n, vector<int>& prices,
                        vector<vector<int>>& roads) {
        vector<pair<int, pair<int, int>>> adj[n + 1];
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], {it[2], it[3]}});
            adj[it[1]].push_back({it[0], {it[2], it[3]}});
        }
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            ans[i] = bfs(n, i, adj, prices);
        }
        return ans;
    }
};