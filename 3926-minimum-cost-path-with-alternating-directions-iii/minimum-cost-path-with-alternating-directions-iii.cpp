class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        priority_queue<pair<long long, pair<int, pair<int, int>>>,
                       vector<pair<long long, pair<int, pair<int, int>>>>,
                       greater<pair<long long, pair<int, pair<int, int>>>>>
            pq;

        pq.push({1, {0, {0, 0}}});

        vector<vector<vector<long long>>> dist(
            m, vector<vector<long long>>(n, vector<long long>(2, LLONG_MAX)));

        dist[0][0][0] = 1;

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            long long c = cur.first;
            int x = cur.second.first;
            int y = cur.second.second.first;
            int action = cur.second.second.second;

            if (c != dist[x][y][action])
                continue;

            if (x == m - 1 && y == n - 1)
                return c;
            int nxt = action ^ 1;
            if (dist[x][y][nxt] > c + penalty[x][y]) {
                dist[x][y][nxt] = c + penalty[x][y];
                pq.push({dist[x][y][nxt], {x, {y, nxt}}});
            }

            if (action == 0) {
                int dr[2] = {0, 1};
                int dc[2] = {1, 0};

                for (int k = 0; k < 2; k++) {
                    int nx = x + dr[k];
                    int ny = y + dc[k];

                    if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                        long long nc = c + 1LL * (nx + 1) * (ny + 1);
                        if (dist[nx][ny][1] > nc) {
                            dist[nx][ny][1] = nc;
                            pq.push({nc, {nx, {ny, 1}}});
                        }
                    }
                }
                int pr[2] = {0, -1};
                int pc[2] = {-1, 0};

                for (int k = 0; k < 2; k++) {
                    int nx = x + pr[k];
                    int ny = y + pc[k];

                    if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                        long long nc =
                            c + 1LL * (nx + 1) * (ny + 1) + penalty[x][y];

                        if (dist[nx][ny][1] > nc) {
                            dist[nx][ny][1] = nc;
                            pq.push({nc, {nx, {ny, 1}}});
                        }
                    }
                }

            } else {
                int dr[2] = {0, -1};
                int dc[2] = {-1, 0};

                for (int k = 0; k < 2; k++) {
                    int nx = x + dr[k];
                    int ny = y + dc[k];

                    if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                        long long nc = c + 1LL * (nx + 1) * (ny + 1);

                        if (dist[nx][ny][0] > nc) {
                            dist[nx][ny][0] = nc;
                            pq.push({nc, {nx, {ny, 0}}});
                        }
                    }
                }
                int pr[2] = {0, 1};
                int pc[2] = {1, 0};

                for (int k = 0; k < 2; k++) {
                    int nx = x + pr[k];
                    int ny = y + pc[k];

                    if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                        long long nc =
                            c + 1LL * (nx + 1) * (ny + 1) + penalty[x][y];

                        if (dist[nx][ny][0] > nc) {
                            dist[nx][ny][0] = nc;
                            pq.push({nc, {nx, {ny, 0}}});
                        }
                    }
                }
            }
        }

        return -1;
    }
};