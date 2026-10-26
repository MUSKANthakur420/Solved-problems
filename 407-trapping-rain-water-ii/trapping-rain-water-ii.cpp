class Solution {
public:
    int trapRainWater(vector<vector<int>>& arr) {
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        int m = arr.size(), n = arr[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0 || j == n - 1 || i == m - 1) {
                    vis[i][j] = 1;
                    pq.push({arr[i][j], {i, j}});
                }
            }
        }
        int ans = 0;
        while (!pq.empty()) {
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            int maxh = pq.top().first;
            pq.pop();
            vector<int> drow = {0, 1, 0, -1};
            vector<int> dcol = {1, 0, -1, 0};
            for (int k = 0; k < 4; k++) {
                int dx = drow[k] + r;
                int dy = dcol[k] + c;
                if (dx >= 0 && dy >= 0 && dx < m && dy < n && !vis[dx][dy]) {
                    int newmaxh = maxh - arr[dx][dy];
                    if (newmaxh < 0) {
                        vis[dx][dy] = 1;
                        pq.push({arr[dx][dy], {dx, dy}});
                    } else {
                        vis[dx][dy] = 1;
                        ans += newmaxh;
                        pq.push({newmaxh + arr[dx][dy], {dx, dy}});
                    }
                }
            }
        }
        return ans;
    }
};