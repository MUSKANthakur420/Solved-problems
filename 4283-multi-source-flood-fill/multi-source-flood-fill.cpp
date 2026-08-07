class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> dp(n, vector<int>(m, 0));
        vector<vector<int>> stamp(n, vector<int>(m, -1));
        unordered_set<string> st;
        queue<pair<int, pair<int, int>>> q;
        for (auto it : sources) {
            int r = it[0], c = it[1], val = it[2];
            dp[r][c] = val;
            stamp[r][c] = 0;
            q.push({0, {r, c}});
            st.insert(to_string(r) + " " + to_string(c));
        }
        while (!q.empty()) {
            int time = q.front().first;
            int r = q.front().second.first, c = q.front().second.second;
            q.pop();
            vector<int> drow = {0, 1, 0, -1};
            vector<int> dcol = {-1, 0, 1, 0};
            for (int k = 0; k < 4; k++) {
                int dx = drow[k] + r;
                int dy = dcol[k] + c;
                if (dx >= 0 && dx < n && dy >= 0 && dy < m) {
                    if (!st.count(to_string(dx) + " " + to_string(dy))) {
                        dp[dx][dy] = dp[r][c];
                        q.push({time + 1, {dx, dy}});
                        st.insert(to_string(dx) + " " + to_string(dy));
                        stamp[dx][dy] = time + 1;
                    } else {
                        if (stamp[dx][dy] == time + 1) {
                            dp[dx][dy] = max(dp[dx][dy], dp[r][c]);
                        }
                    }
                }
            }
        }
        return dp;
    }
};