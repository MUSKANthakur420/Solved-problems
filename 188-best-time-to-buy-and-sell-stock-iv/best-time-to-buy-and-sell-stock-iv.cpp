class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> dp(2 * k + 1, 0);
        for (int i = prices.size() - 1; i >= 0; i--) {
            for (int t = 2 * k - 1; t >= 0; t--) {
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