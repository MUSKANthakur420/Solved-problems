class Solution {
public:
    int solve(int i, int j, string& s, string& t) {
        if (j == t.size())
            return 1;
        if (i >= s.size())
            return 0;
        if (s[i] == t[j])
            return solve(i + 1, j + 1, s, t) + solve(i + 1, j, s, t);
        return solve(i + 1, j, s, t);
    }
    int numDistinct(string s, string t) {
        vector<long long int> dp(t.size() + 1, 0LL);
        dp[t.size()] = 1LL;
        for (int i = s.size() - 1; i >= 0; i--) {
            vector<long long> curr(t.size() + 1, 0LL);
            curr[t.size()] = 1LL;
            for (int j = t.size() - 1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    curr[j] = (dp[j + 1] % INT_MAX + dp[j] % INT_MAX) % INT_MAX;
                } else
                    curr[j] = dp[j];
            }
            dp = curr;
        }
        return dp[0];
    }
};