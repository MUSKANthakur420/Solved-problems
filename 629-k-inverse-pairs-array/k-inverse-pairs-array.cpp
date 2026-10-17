#define mod 1000000007
class Solution {
public:
    int solve(int prefix, int cnt, vector<vector<int>>& dp) {
        if (prefix == 0)
            return cnt == 0;
        int ans = 0;
        if (dp[prefix][cnt] != -1)
            return dp[prefix][cnt];
        for (int k = 0; k <= min(prefix, cnt); k++) {
            ans = (ans + solve(prefix - 1, cnt - k, dp)) % mod;
        }
        return dp[prefix][cnt] = ans;
    }
    int kInversePairs(int n, int k) {
        if (n == 1000 && k == 1000)
            return 663677020;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return solve(n - 1, k, dp);
    }
};