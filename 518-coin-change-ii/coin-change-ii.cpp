class Solution {
public:
    int solve(int indx, vector<int>& coins, int sum, int t,
              vector<vector<int>>& dp) {
        if (sum == t) {
            return 1;
        }
        if (indx == coins.size() || sum > t)
            return 0;
        if (dp[indx][sum] != -1)
            return dp[indx][sum];
        int take = 0;
        if (sum + coins[indx] <= t)
            take = solve(indx, coins, sum + coins[indx], t, dp);
        int notake = solve(indx + 1, coins, sum, t, dp);
        return dp[indx][sum] = take + notake;
    }
    int change(int amount, vector<int>& coins) {
        vector<long long> dp(amount + 1, 0LL);
        dp[amount] = 1LL;
        for (int indx = coins.size() - 1; indx >= 0; indx--) {
            for (int sum = amount - 1; sum >= 0; sum--) {
                long long notake = dp[sum];
                long long take = 0;
                if (sum + coins[indx] <= amount)
                    take = dp[sum + coins[indx]];
                dp[sum] = (take + notake) % INT_MAX;
            }
        }
        return dp[0];
    }
};