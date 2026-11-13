class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(int i, int j1, int j2, int m, int n, vector<vector<int>>& grid) {
        if (i == m)
            return 0;
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        vector<int> drow = {1, 1, 1};
        vector<int> dcol = {-1, 0, 1};
        int ans = -1e9;
        for (int k = 0; k < 3; k++) {
            int dj1 = dcol[k] + j1;
            if (dj1 >= 0 && dj1 < n) {
                for (int t = 0; t < 3; t++) {
                    int dj2 = dcol[t] + j2;
                    if (dj2 >= 0 && dj2 < n)
                        if (dj1 != dj2) {
                            ans = max(ans,
                                      grid[i][j1] + grid[i][j2] +
                                          solve(i + 1, dj1, dj2, m, n, grid));
                        }
                }
            }
        }
        return dp[i][j1][j2] = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        dp.assign(grid.size() + 1,
                  vector<vector<int>>(grid[0].size() + 1,
                                      vector<int>(grid[0].size() + 1, -1)));
        return solve(0, 0, grid[0].size() - 1, grid.size(), grid[0].size(),
                     grid);
    }
};