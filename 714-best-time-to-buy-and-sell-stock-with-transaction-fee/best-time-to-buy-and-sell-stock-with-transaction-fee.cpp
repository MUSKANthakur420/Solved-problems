class Solution {
public:
    int solve(int indx, int fee, vector<int>& prices, int buy) {
        if (indx == prices.size())
            return 0;
        int take = 0, notake = 0;
        if (buy) {
            take = max(-prices[indx] + solve(indx + 1, fee, prices, 0),
                       solve(indx + 1, fee, prices, 1));
        } else
            notake = max(prices[indx] - fee + solve(indx + 1, fee, prices, 1),
                         solve(indx + 1, fee, prices, 0));
        return max(take, notake);
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> dp(2, 0);
        for (int indx = prices.size() - 1; indx >= 0; indx--) {
            for (int buy = 1; buy >= 0; buy--) {
                int take = 0, notake = 0;
                if (buy) {
                    take = max(-prices[indx] + dp[0], dp[1]);
                } else
                    notake = max(prices[indx] + dp[1] - fee, dp[0]);
                dp[buy] = max(take, notake);
            }
        }
        return dp[1];
    }
};