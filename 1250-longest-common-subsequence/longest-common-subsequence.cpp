class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, string& s, string& t) {
        if (i == s.size() || j == t.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        if (s[i] == t[j]) {
            ans = 1 + solve(i + 1, j + 1, s, t);
        } else {
            ans = max({ans, solve(i, j + 1, s, t), solve(i + 1, j, s, t)});
        }
        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string s, string t) {
        dp.assign(s.size() + 1, vector<int>(t.size() + 1, -1));
        return solve(0, 0, s, t);
    }
};