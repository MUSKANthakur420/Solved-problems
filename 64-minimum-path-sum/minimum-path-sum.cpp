class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, int m, int n, vector<vector<int>>& grid) {
        if (i == m - 1 && j == n - 1)
            return grid[m - 1][n - 1];
        if (dp[i][j] != -1)
            return dp[i][j];
        vector<int> drow = {1, 0};
        vector<int> dcol = {0, 1};
        int ans = 1e9;
        for (int k = 0; k < 2; k++) {
            int di = drow[k] + i;
            int dj = dcol[k] + j;
            if (di >= 0 && dj >= 0 && di < m && dj < n) {
                ans = min(ans, grid[i][j] + solve(di, dj, m, n, grid));
            }
        }
        return dp[i][j] = ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        dp.assign(grid.size() + 1, vector<int>(grid[0].size() + 1, -1));
        return solve(0, 0, grid.size(), grid[0].size(), grid);
    }
};