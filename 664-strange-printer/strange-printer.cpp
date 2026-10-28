class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, string& s) {
        if (i == j)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        int mini = INT_MAX;
        for (int k = i; k < j; k++) {
            mini = min(mini, solve(i, k, s) + solve(k + 1, j, s));
        }
        if (s[i] == s[j])
            mini -= 1;
        return dp[i][j] = mini;
    }
    int strangePrinter(string s) {
        dp.assign(s.size() + 1, vector<int>(s.size() + 1, -1));
        return solve(0, s.size() - 1, s);
    }
};