class Solution {
public:
    int dfs(int x, int y, int m, int n, vector<vector<int>>& dp) {
        if (x == 0 && y == 0)
            return 1;
        if (dp[x][y] != -1)
            return dp[x][y];
        int up = 0, left = 0;
        if (x - 1 >= 0)
            up = dfs(x - 1, y, m, n, dp);
        if (y - 1 >= 0)
            left = dfs(x, y - 1, m, n, dp);
        return dp[x][y] = up + left;
    }
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] = dp[j] + dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};