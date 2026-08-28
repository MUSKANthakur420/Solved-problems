class Solution {
public:
    int solve(int indx, vector<int>& prices, vector<vector<int>>& dp, int t) {
        if (indx == prices.size() || t == 4)
            return 0;
        if (dp[indx][t] != -1)
            return dp[indx][t];
        int take = 0, notake = 0;
        if (t % 2 == 0) {
            take = max(-prices[indx] + solve(indx + 1, prices, dp, t + 1),
                       solve(indx + 1, prices, dp, t));
        } else {
            notake = max(prices[indx] + solve(indx + 1, prices, dp, t + 1),
                         solve(indx + 1, prices, dp, t));
        }
        return dp[indx][t] = max(take, notake);
    }
    int maxProfit(vector<int>& prices) {
        vector<int> dp(5, 0);
        for (int i = prices.size() - 1; i >= 0; i--) {
            for (int t = 3; t >= 0; t--) {
                int take = 0, notake = 0;
                if (t % 2 == 0)
                    take = max(-prices[i] + dp[t + 1], dp[t]);
                else
                    notake = max(prices[i] + dp[t + 1], dp[t]);
                dp[t] = max(take, notake);
            }
        }
        return dp[0];
    }
};