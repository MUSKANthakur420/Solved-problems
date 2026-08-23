class Solution {
public:
    // int solve(int i, int j, strin a, string b) {
    //     if (i >= a.size() || j >= b.size())
    //         return 0;
    //     if (a[i] == b[j]) {
    //         return 1 + solve(i + 1, j + 1, a, b);
    //     }
    //     return max(solve(i, j + 1, a, b), solve(i + 1, j, a, b));
    // }
    int longestPalindromeSubseq(string s) {
        string b = s;
        reverse(b.begin(), b.end());
        vector<int> dp(s.size() + 1);
        for (int i = s.size() - 1; i >= 0; i--) {
            vector<int> curr(s.size() + 1);
            for (int j = s.size() - 1; j >= 0; j--) {
                if (s[i] == b[j]) {
                    curr[j] = 1 + dp[j + 1];
                } else
                    curr[j] = max(curr[j + 1], dp[j]);
            }
            dp = curr;
        }
        return dp[0];
    }
};