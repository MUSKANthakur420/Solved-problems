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
        int x0 = 0, x1 = 0;
        for (int i = prices.size() - 1; i >= 0; i--) {
            for (int j = 1; j >= 0; j--) {
                int take = 0, notake = 0;
                if (j) {
                    x1 = max(-prices[i] + x0, x1);
                } else
                    x0 = max(prices[i] + x1, x0);
            }
        }
        return x1;
    }
};