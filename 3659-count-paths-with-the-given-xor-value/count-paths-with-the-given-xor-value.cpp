#define mod 1000000007
class Solution {
public:
    // int solve(vector<vector<int>>& grid, int k) {
    //     int m = grid.size(), n = grid[0].size();
    //     queue<pair<int, pair<int, int>>> q;
    //     vector<vector<vector<int>>> dp(
    //         m, vector<vector<int>>(n, vector<int>(16, 0)));
    //     dp[0][0][grid[0][0]] = 1;
    //     q.push({grid[0][0], {0, 0}});
    //     while (!q.empty()) {
    //         int size = q.size();
    //         for (int i = 0; i < size; i++) {
    //             int x = q.front().second.first;
    //             int y = q.front().second.second;
    //             int val = q.front().first;
    //             q.pop();
    //             vector<int> drow = {0, 1};
    //             vector<int> dcol = {1, 0};
    //             for (int z = 0; z < 2; z++) {
    //                 int dx = drow[z] + x;
    //                 int dy = dcol[z] + y;
    //                 if (dx < m && dy < n) {
    //                     int newval = val ^ grid[dx][dy];
    //                     dp[dx][dy][newval] = dp[dx][dy][newval] % mod + 1;
    //                     q.push({newval, {dx, dy}});
    //                 }
    //             }
    //         }
    //     }
    //     return dp[m - 1][n - 1][k] % mod;
    // }
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(16, 0)));
        dp[0][0][grid[0][0]] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vector<int> drow = {0, 1};
                vector<int> dcol = {1, 0};
                for (int z = 0; z < 2; z++) {
                    int dx = drow[z] + i;
                    int dy = dcol[z] + j;
                    if (dx < m && dy < n) {
                        for (int xorval = 0; xorval< 16; xorval++) {
                            if (dp[i][j][xorval] != 0) {
                                int newxor = xorval ^ grid[dx][dy];
                                dp[dx][dy][newxor] = (dp[dx][dy][newxor] % mod +
                                                      dp[i][j][xorval] % mod) %
                                                     mod;
                            }
                        }
                    }
                }
            }
        }
        return dp[m - 1][n - 1][k];
    }
};