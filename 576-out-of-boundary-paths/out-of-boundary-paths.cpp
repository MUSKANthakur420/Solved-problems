#define mod 1000000007
class Solution {
public:
    int solve(int i, int j, int moves, int m, int n, int maxi,
              vector<vector<vector<int>>>& dp) {
        if ((i < 0 || j < 0 || i >= m || j >= n))
            return 1;
        vector<int> drow = {0, 1, 0, -1};
        vector<int> dcol = {1, 0, -1, 0};
        if (dp[i][j][moves] != -1)
            return dp[i][j][moves];
        int ans = 0;
        for (int k = 0; k < 4; k++) {
            int dx = drow[k] + i;
            int dy = dcol[k] + j;
            if (moves + 1 <= maxi) {
                ans = (ans % mod +
                       solve(dx, dy, moves + 1, m, n, maxi, dp) % mod) %
                      mod;
            }
        }
        return dp[i][j][moves] = ans;
    }
    int findPaths(int m, int n, int maxi, int i, int j) {
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(maxi + 1, -1)));
        return solve(i, j, 0, m, n, maxi, dp);
    }
};