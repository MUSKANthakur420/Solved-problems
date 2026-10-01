#define mod 1000000007
class Solution {
public:
    int solve(int sum, int k, int size, int n, vector<vector<int>>& dp) {
        if (sum == 0 && size == n) {
            return 1;
        }
        if (sum < 0 || size > n)
            return 0;
        if (dp[sum][size] != -1)
            return dp[sum][size];
        int ans = 0;
        for (int i = 1; i <= k; i++) {
            ans = (ans % mod + solve(sum - i, k, size + 1, n, dp) % mod) % mod;
        }
        return dp[sum][size] = ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        if (n == 1 && target <= k) {
            return 1;
        }
        if (n == 1 && target > k)
            return 0;
        vector<vector<int>> dp(target + 1, vector<int>(n + 1, -1));
        return solve(target, k, 0, n, dp);
    }
};