class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, string& s, string& t) {
        if (i == s.size()) {
            if (j == t.size())
                return 1;
            return 0;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        if (s[i] == t[j]) {
            ans += solve(i + 1, j + 1, s, t);
        }
        ans += solve(i + 1, j, s, t);
        return dp[i][j] = ans;
    }
    int numDistinct(string s, string t) {
        dp.assign(s.size() + 1, vector<int>(t.size() + 1, -1));
        return solve(0, 0, s, t);
    }
};