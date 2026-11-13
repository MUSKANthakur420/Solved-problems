class Solution {
public:
    vector<vector<int>> dp;
    bool solve(int i, int j, string& s, string& p) {
        if (i == s.size()) {
            if (j == p.size())
                return true;
            for (int k = j; k < p.size(); k++) {
                if (p[k] != '*')
                    return false;
            }
        }
        if (j >= p.size())
            return false;
        if (dp[i][j] != -1)
            return dp[i][j];
        bool ans = false;
        if (s[i] == p[j] || p[j] == '?') {
            ans |= solve(i + 1, j + 1, s, p);
        }
        if (p[j] == '*') {
            for (int k = i; k < s.size(); k++) {
                ans |= solve(k + 1, j + 1, s, p);
            }
        }
        return dp[i][j] = ans;
    }
    bool isMatch(string s, string p) {
        dp.assign(s.size() + 1, vector<int>(p.size() + 1, 0));
        dp[s.size()][p.size()] = true;
        for (int j = p.size() - 1; j >= 0; j--) {
            dp[s.size()][j] = (p[j] == '*' && dp[s.size()][j + 1]);
        }
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = p.size() - 1; j >= 0; j--) {
                if (s[i] == p[j] || p[j] == '?') {
                    dp[i][j] |= dp[i + 1][j + 1];
                }
                if (p[j] == '*') {
                    dp[i][j] = (dp[i][j + 1] | dp[i + 1][j]);
                }
            }
        }
        return dp[0][0];
    }
};