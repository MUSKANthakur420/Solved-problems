class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        queue<pair<int, pair<int, int>>> pq;
        vector<vector<vector<double>>> dp(
            n + 2, vector<vector<double>>(n + 2, vector<double>(k + 2, 0)));
        pq.push({0, {row, column}});
        dp[row][column][0] = 1;
        for (int move = 0; move <= k; move++) {
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    if (x - 1 >= 0 && y + 2 < n && move + 1 <= k) {
                        dp[x - 1][y + 2][move + 1] += dp[x][y][move] / 8.0;
                    }
                    if (x + 1 < n && y + 2 < n && move + 1 <= k) {
                        dp[x + 1][y + 2][move + 1] += dp[x][y][move] / 8.0;
                    }
                    if (x - 1 >= 0 && y - 2 >= 0 && move + 1 <= k) {
                        dp[x - 1][y - 2][move + 1] += dp[x][y][move] / 8.0;
                    }
                    if (x + 1 < n && y - 2 >= 0 && move + 1 <= k) {
                        dp[x + 1][y - 2][move + 1] += dp[x][y][move] / 8.0;
                    }

                    if (x - 2 >= 0 && y + 1 < n && move + 1 <= k) {
                        dp[x - 2][y + 1][move + 1] += dp[x][y][move] / 8.0;
                    }
                    if (x - 2 >= 0 && y - 1 >= 0 && move + 1 <= k) {
                        dp[x - 2][y - 1][move + 1] += dp[x][y][move] / 8.0;
                    }
                    if (x + 2 < n && y + 1 < n && move + 1 <= k) {
                        dp[x + 2][y + 1][move + 1] += dp[x][y][move] / 8.0;
                    }
                    if (x + 2 < n && y - 1 >= 0 && move + 1 <= k) {
                        dp[x + 2][y - 1][move + 1] += dp[x][y][move] / 8.0;
                    }
                }
            }
        }
        double cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cnt += dp[i][j][k];
            }
        }
        return cnt;
    }
};