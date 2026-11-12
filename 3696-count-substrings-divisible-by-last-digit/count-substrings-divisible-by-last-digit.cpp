class Solution {
public:
    long long countSubstrings(string s) {
        vector<vector<vector<long long>>> dp(
            s.size() + 1, vector<vector<long long>>(10, vector<long long>(10, 0LL)));
        long long ans = 0LL;
        for (int i = 0; i < s.size(); i++) {
            int digit = s[i] - '0';
            for (int d = 1; d <= 9; d++) {
                for (int r = 0; r < d; r++) {
                    int nr = (r * 10 + digit) % d;
                    dp[i][d][nr] += (i == 0) ? 0 : dp[i - 1][d][r];
                }
                dp[i][d][digit % d]++;
            }
            ans += dp[i][digit][0];
        }
        return ans;
    }
};