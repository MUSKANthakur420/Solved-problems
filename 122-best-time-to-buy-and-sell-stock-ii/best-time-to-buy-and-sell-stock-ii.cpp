class Solution {
public:
    int solve(int indx, vector<int>& prices, int flag,
              vector<vector<int>>& dp) {
        if (indx == prices.size())
            return 0;
        int take = 0, notake = 0;
        if (dp[indx][flag] != -1)
            return dp[indx][flag];
        if (flag) {
            take = max(-prices[indx] + solve(indx + 1, prices, 0, dp),
                       solve(indx + 1, prices, 1, dp));
        } else {
            notake = max(prices[indx] + solve(indx + 1, prices, 1, dp),
                         solve(indx + 1, prices, 0, dp));
        }
        return dp[indx][flag] = max(take, notake);
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(3, -1));
        dp[prices.size()][1] = 0, dp[prices.size()][0] = 0;
        for (int i = prices.size() - 1; i >= 0; i--) {
            for (int j = 1; j >= 0; j--) {
                int take = 0, notake = 0;
                if (j) {
                    take = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
                } else
                    notake = max(prices[i] + dp[i + 1][1], dp[i + 1][0]);
                dp[i][j] = max(take, notake);
            }
        }
        return dp[0][1];
    }
};