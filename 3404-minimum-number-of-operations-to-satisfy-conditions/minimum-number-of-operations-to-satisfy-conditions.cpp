class Solution {
public:
    int solve(int j, int digit, int m, int n, vector<vector<int>>& grid,
              vector<vector<int>>& dp) {
        if (j >= n)
            return 0;
        if (dp[j][digit] != -1)
            return dp[j][digit];
        int mini = 0, res = INT_MAX;
        for (int i = 0; i < m; i++) {
            if (grid[i][j] != digit)
                mini += 1;
        }
        for (int num = 0; num <= 9; num++) {
            if (num == digit)
                continue;
            res = min(res, mini + solve(j + 1, num, m, n, grid, dp));
        }
        return dp[j][digit] = res;
    }
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(10, -1));
        int res = INT_MAX;
        for (int digit = 0; digit <= 9; digit++) {
            res = min(res, solve(0, digit, m, n, grid, dp));
        }
        return res;
    }
};