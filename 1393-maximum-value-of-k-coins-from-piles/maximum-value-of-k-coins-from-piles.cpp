class Solution {
public:
    vector<vector<int>> dp;
    // int solve(int indx, int k, int t, vector<vector<int>>& piles) {
    //     if (k == 0)
    //         return 0;
    //     if (indx >= piles.size() || t >= piles[indx].size())
    //         return -1e9;
    //     if (dp[indx][t][k] != -1)
    //         return dp[indx][t][k];
    //     int notake = solve(indx + 1, k, 0, piles);
    //     int take = -1e9;
    //     take =
    //         max(take, piles[indx][t] + max(solve(indx, k - 1, t + 1, piles),
    //                                        solve(indx + 1, k - 1, 0,
    //                                        piles)));
    //     return dp[indx][t][k] = max(take, notake);
    // }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int colsize = 0;
        for (int i = 0; i < piles.size(); i++) {
            colsize = max(colsize, (int)piles[i].size());
        }
        dp.assign(colsize + 1, vector<int>(k + 1, 0));
        for (int indx = piles.size() - 1; indx >= 0; indx--) {
            vector<vector<int>> curr(colsize + 1, vector<int>(k + 1, 0));
            for (int t = piles[indx].size() - 1; t >= 0; t--) {
                for (int r = 1; r <= k; r++) {
                    int notake = dp[0][r];
                    int take = -1e9;
                    take = max(take, piles[indx][t] +
                                         max(curr[t + 1][r - 1], dp[0][r - 1]));
                    curr[t][r] = max(take, notake);
                }
            }
            dp = curr;
        }
        return dp[0][k];
    }
};