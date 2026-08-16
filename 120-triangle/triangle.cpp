class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>>& triangle,
              vector<vector<int>>& dp) {
        if (i == m - 1) {
            return triangle[i][j];
        }
        int row = 0, col = 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (i + 1 < m)
            row = triangle[i][j] + solve(i + 1, j, m, n, triangle, dp);
        if (i + 1 < m && j + 1 < n)
            col = triangle[i][j] + solve(i + 1, j + 1, m, n, triangle, dp);
        return dp[i][j] = min(row, col);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m - 1].size();
        vector<int> dp(n, 0);
        for (int j = 0; j < n; j++) {
            dp[j] = triangle[m - 1][j];
        }
        for (int i = m - 2; i >= 0; i--) {
            vector<int> curr(n, 0);
            for (int j = triangle[i].size() - 1; j >= 0; j--) {
                curr[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
            dp = curr;
        }
        return dp[0];
    }
};