class Solution {
public:
    int solve(int i, int j, string& s, string& rev) {
        if (i >= s.size() || j >= s.size())
            return 0;
        if (s[i] == rev[j]) {
            return 1 + solve(i + 1, j + 1, s, rev);
        }
        return max(solve(i, j + 1, s, rev), solve(i + 1, j, s, rev));
    }
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(s.begin(), s.end());
        vector<int> dp(s.size() + 1, 0);
        for (int i = s.size() - 1; i >= 0; i--) {
            vector<int> curr(s.size() + 1, 0);
            for (int j = s.size() - 1; j >= 0; j--) {
                if (s[i] == rev[j])
                    curr[j] = dp[j + 1] + 1;
                else
                    curr[j] = max(curr[j + 1], dp[j]);
            }
            dp = curr;
        }
        return dp[0];
    }
};