class Solution {
public:
    bool solve(int i, int j, string& s, string& t) {
        if (j == t.size() && i == s.size())
            return true;
        if (i == s.size()) {
            for (int k = j; k < t.size(); k++) {
                if (t[k] != '*')
                    return false;
            }
            return true;
        }
        if (s[i] == t[j])
            return solve(i + 1, j + 1, s, t);
        if (t[j] == '*')
            return solve(i, j + 1, s, t) || solve(i + 1, j, s, t);
        if (t[j] == '?')
            return solve(i + 1, j + 1, s, t);
        return false;
    }
    bool isMatch(string s, string p) {
        vector<int> dp(p.size() + 1, 0);
        dp[p.size()] = true;
        for (int j = p.size() - 1; j >= 0; j--) {
            if (p[j] == '*')
                dp[j] = dp[j + 1];
            else
                dp[j] = false;
        }
        for (int i = s.size() - 1; i >= 0; i--) {
            vector<int> curr(p.size() + 1, 0);
            if (i == s.size())
                curr[p.size()] = true;
            for (int j = p.size() - 1; j >= 0; j--) {
                if (s[i] == p[j])
                    curr[j] = dp[j + 1];
                if (p[j] == '*')
                    curr[j] = curr[j + 1] || dp[j];
                if (p[j] == '?')
                    curr[j] = dp[j + 1];
            }
            dp = curr;
        }
        return dp[0];
    }
};