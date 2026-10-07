class Solution {
public:
    int solve(int i, int j, int k, string& s, vector<vector<vector<int>>>& dp) {
        if (i > j)
            return 0;
        if (i == j)
            return 1;
        if (dp[i][j][k] != -1)
            return dp[i][j][k];
        int notake = max(solve(i, j - 1, k, s, dp), solve(i + 1, j, k, s, dp));
        int diff = abs(s[i] - s[j]);
        diff = min(diff, 26 - diff);
        int take = 0;
        if (diff <= k) {
            take = 2 + solve(i + 1, j - 1, k - diff, s, dp);
        }
        return dp[i][j][k] = max(take, notake);
    }
    int longestPalindromicSubsequence(string s, int k) {
        vector<vector<vector<int>>> dp(
            s.size(), vector<vector<int>>(s.size(), vector<int>(201, -1)));
        return solve(0, s.size() - 1, k, s, dp);
    }
};