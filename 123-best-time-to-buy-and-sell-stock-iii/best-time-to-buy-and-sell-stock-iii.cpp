class Solution {
public:
    int solve(int indx, vector<int>& prices, int flag,
              vector<vector<vector<int>>>& dp, int t) {
        if (indx == prices.size())
            return 0;
        if (t == 2)
            return 0;
        int take = 0, notake = 0;
        if (dp[indx][flag][t] != -1)
            return dp[indx][flag][t];
        if (flag) {
            take = max(-prices[indx] + solve(indx + 1, prices, 0, dp, t),
                       solve(indx + 1, prices, 1, dp, t));
        } else {
            notake = max(prices[indx] + solve(indx + 1, prices, 1, dp, t + 1),
                         solve(indx + 1, prices, 0, dp, t));
        }
        return dp[indx][flag][t] = max(take, notake);
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(
            prices.size() + 1, vector<vector<int>>(3, vector<int>(3, -1)));
        // dp[prices.size()][0][2] = 0, dp[prices.size()][1][2] = 0;
        // for (int i = prices.size() - 1; i >= 0; i--) {
        //     for (int j = 1; j >= 0; j--) {
        //         for (int t = 2; t >= 0; t--) {
        //             int take = 0, notake = 0;
        //             if (t == 2 && j == 1)
        //                 continue;
        //             if (j) {
        //                 take =
        //                     max(-prices[i] + dp[i + 1][0][t], dp[i +
        //                     1][1][t]);
        //             } else
        //                 notake = max(prices[i] + dp[i + 1][1][t + 1],
        //                              dp[i + 1][0][t]);

        //             dp[i][j][t] = max(take, notake);
        //         }
        //     }
        // }
        solve(0, prices, 1, dp, 0);
        return max({dp[0][1][0], dp[0][1][1], dp[0][1][2]});
    }
};