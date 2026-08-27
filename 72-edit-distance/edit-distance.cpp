class Solution {
public:
    int solve(int i, int j, string& s, string& t) {
        if (j == t.size())
            return s.size() - i;
        if (i == s.size())
            return t.size() - j;
        if (s[i] == t[j])
            return solve(i + 1, j + 1, s, t);
        return min({1 + solve(i + 1, j + 1, s, t), 1 + solve(i + 1, j, s, t),
                    1 + solve(i + 1, j + 1, s, t)});
    }
    int minDistance(string s, string t) {
        vector<int> dp(t.size() + 1, 0);
        for (int j = t.size(); j >= 0; j--)
            dp[j] = t.size() - j;
        for (int i = s.size() - 1; i >= 0; i--) {
            vector<int> curr(t.size() + 1, 0);
            curr[t.size()] = s.size() - i;
            for (int j = t.size() - 1; j >= 0; j--) {
                if (s[i] == t[j])
                    curr[j] = dp[j + 1];
                else
                    curr[j] = 1 + min({dp[j + 1], curr[j + 1], dp[j]});
            }
            dp = curr;
        }
        return dp[0];
    }
};