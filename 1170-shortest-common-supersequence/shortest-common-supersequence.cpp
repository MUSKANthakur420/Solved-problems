class Solution {
public:
    string shortestCommonSupersequence(string s, string rev) {
        int n = s.size(), m = rev.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s[i] == rev[j])
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                else
                    dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
        string ans = "";
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (s[i] == rev[j]) {
                ans += s[i];
                i++;
                j++;
            } else {
                if (dp[i][j + 1] > dp[i + 1][j]) {
                    ans += rev[j];
                    j++;
                } else {
                    ans += s[i];
                    i++;
                }
            }
        }
        while (i < n) {
            ans += s[i++];
        }
        while (j < m)
            ans += rev[j++];
        return ans;
    }
};