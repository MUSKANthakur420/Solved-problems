#define mod 1000000007
class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(int p, int a, int l, int n) {
        if (l >= 3 || a >= 2)
            return 0;
        if (p == n) {
            return 1;
        }
        if (p > n)
            return 0;
        if (dp[p][a][l] != -1)
            return dp[p][a][l];
        int ans = solve(p + 1, a, 0, n) % mod;
        if (a < 2) {
            ans = (ans + solve(p + 1, a + 1, 0, n)) % mod;
        }
        if (l < 3) {
            ans = (ans + solve(p + 1, a, l + 1, n)) % mod;
        }
        return dp[p][a][l] = ans % mod;
    }
    int checkRecord(int n) {
        dp.assign(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, 0, 0, n);
    }
};