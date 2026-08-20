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
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        solve(0, coins, amount, 0LL, dp);
        return dp[0][0] == 1e9 ? -1 : dp[0][0];
    }
};