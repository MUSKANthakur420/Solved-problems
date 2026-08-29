class Solution {
public:
    int solve(int indx, vector<int>& prices, int buy, bool coolday,
              vector<vector<vector<int>>>& dp) {
        if (indx == prices.size())
            return 0;
        int take = 0, notake = 0;
        if (dp[indx][buy][coolday] != -1)
            return dp[indx][buy][coolday];
        if (buy && coolday) {
            return solve(indx + 1, prices, 1, false, dp);
        }
        if (buy && !coolday) {
            take = max(-prices[indx] + solve(indx + 1, prices, 0, false, dp),
                       solve(indx + 1, prices, 1, false, dp));
        } else {
            notake = max(prices[indx] + solve(indx + 1, prices, 1, true, dp),
                         solve(indx + 1, prices, 0, false, dp));
        }
        return dp[indx][buy][coolday] = max(take, notake);
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(2, vector<int>(2, 0));
        for (int indx = prices.size() - 1; indx >= 0; indx--) {
            vector<vector<int>> curr(2, vector<int>(2, 0));
            for (int buy = 1; buy >= 0; buy--) {
                for (int day = 0; day <= 1; day++) {
                    if (buy == 1 && day == 1) {
                        curr[buy][day] = dp[1][false];
                        continue;
                    }
                    int take = 0, notake = 0;
                    if (buy && !day) {
                        take = max(-prices[indx] + dp[0][false], dp[1][false]);
                    } else
                        notake = max(prices[indx] + dp[1][true], dp[0][false]);

                    curr[buy][day] = max(take, notake);
                }
            }
            dp = curr;
        }
        return dp[1][false];
    }
};