#define mod 1000000007
class Solution {
public:
    // int cnt = 0;
    int solve(int s, int low, int high, int zero, int one,
              vector<long long>& dp) {
        if (s > high) {
            return 0;
        }
        if (dp[s] != -1)
            return dp[s];
        long long int cnt = (s >= low);
        cnt =
            (cnt % mod + solve(s + one, low, high, zero, one, dp) % mod) % mod;
        cnt =
            (cnt % mod + solve(s + zero, low, high, zero, one, dp) % mod) % mod;
        return dp[s] = cnt % mod;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long> dp(high + 1, -1);
        return solve(0, low, high, zero, one, dp);
    }
};