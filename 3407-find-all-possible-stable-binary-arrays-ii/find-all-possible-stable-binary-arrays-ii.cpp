#define mod 1000000007
class Solution {
public:
    int solve(int zero, int one, int limit, bool last) {
        if (zero == 0 && one == 0)
            return 1;
        int res = 0;
        if (last) {
            for (int len = 1; len <= min(zero, limit); len++) {
                res = (res + solve(zero - len, one, limit, !last) % mod) % mod;
            }
        } else {
            for (int len = 1; len <= min(one, limit); len++) {
                res = (res + solve(zero, one - len, limit, !last) % mod) % mod;
            }
        }
        return (res) % mod;
    }
    int numberOfStableArrays(int z, int o, int limit) {
        vector<vector<vector<int>>> dp(
            z + 1, vector<vector<int>>(o + 1, vector<int>(2, 0)));
        for (int len = 1; len <= min(o, limit); len++)
            dp[0][len][1] = 1;
        for (int len = 1; len <= min(z, limit); len++)
            dp[len][0][0] = 1;
        for (int zero = 0; zero <= z; zero++) {
            for (int one = 0; one <= o; one++) {
                if (zero == 0 || one == 0)
                    continue;
                dp[zero][one][1] =
                    (dp[zero][one - 1][1] + dp[zero][one - 1][0]) % mod;
                if (one - 1 >= limit) {
                    dp[zero][one][1] = (dp[zero][one][1] -
                                        dp[zero][one - 1 - limit][0] + mod) %
                                       mod;
                }
                dp[zero][one][0] =
                    (dp[zero - 1][one][1] + dp[zero - 1][one][0]) % mod;
                if (zero - 1 >= limit) {
                    dp[zero][one][0] = (dp[zero][one][0] -
                                        dp[zero - 1 - limit][one][1] + mod) %
                                       mod;
                }
            }
        }
        return (dp[z][o][1] + dp[z][o][0]) % mod;
    }
};