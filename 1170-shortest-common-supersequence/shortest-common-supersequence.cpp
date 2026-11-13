class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        vector<vector<int>> dp;
        dp.assign(s.size() + 1, vector<int>(t.size() + 1, 0));
        int maxlen = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            int ans = 0;
            for (int j = t.size() - 1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    ans = max({ans, 1 + dp[i + 1][j + 1]});
                } else {
                    ans = max({ans, dp[i][j + 1], dp[i + 1][j]});
                }
                dp[i][j] = ans;
                //   /  maxlen = max(maxlen, dp[i][j]);
            }
        }
        string ans = "";
        int i = 0, j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                ans += s[i];
                i++;
                j++;
            } else {
                if (dp[i][j + 1] > dp[i + 1][j]) {
                    ans += t[j];
                    j++;
                } else {
                    ans += s[i];
                    i++;
                }
            }
        }
        while (i < s.size()) {
            ans += s[i];
            i++;
        }
        while (j < t.size()) {
            ans += t[j];
            j++;
        }
        return ans;
    }
};