class Solution {
public:
    int mini = INT_MAX;
    int solve(int indx, vector<int>& coins, int t, long long sum,
              vector<vector<int>>& dp) {
        if (sum == t) {
            return 0;
        }
        if (indx == coins.size() || sum > t)
            return 1e9;
        if (dp[indx][sum] != -1)
            return dp[indx][sum];
        int take = 1e9;
        if (sum + coins[indx] <= t)
            take = solve(indx, coins, t, sum + coins[indx], dp) + 1;
        int notake = solve(indx + 1, coins, t, sum, dp);
        return dp[indx][sum] = min(take, notake);
    }
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;
        vector<int> dp(amount + 1, 1e9);
        dp[amount] = 0;
        for (int indx = coins.size() - 1; indx >= 0; indx--) {
            for (long long sum = amount; sum >= 0; sum--) {
                int notake = dp[sum];
                int take = 1e9;
                if (sum + coins[indx] <= amount)
                    take = dp[sum + coins[indx]] + 1;
                dp[sum] = min(take, notake);
            }
        }
        return dp[0] == 1e9 ? -1 : dp[0];
    }
};