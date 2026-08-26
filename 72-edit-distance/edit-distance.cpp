class Solution {
public:
    int solve(int i, int j, string& s, string& t) {
        if (j == t.size())
            return s.size() - i;
        if (i == s.size())
            return t.size() - j;
        if (s[i] == t[j])
            return solve(i + 1, j + 1, s, t);
        return min({1 + solve(i + 1, j, s, t), 1 + solve(i + 1, j + 1, s, t),
                    1 + solve(i, j + 1, s, t)});
    }
    int minDistance(string s, string t) {
        int maxi = max(s.size(), t.size());
        vector<int> dp(maxi + 1, 0);
        for (int i = 0; i <= t.size(); i++)
            dp[i] = t.size() - i;
        for (int i = s.size() - 1; i >= 0; i--) {
            vector<int> curr(maxi + 1, 0);
            curr[t.size()] = s.size() - i;
            for (int j = t.size() - 1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    curr[j] = dp[j + 1];
                } else
                    curr[j] = min({1 + dp[j + 1], dp[j] + 1, curr[j + 1] + 1});
            }
            dp = curr;
        }
        return dp[0];
    }
};