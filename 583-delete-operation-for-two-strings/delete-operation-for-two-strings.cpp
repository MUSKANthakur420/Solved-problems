class Solution {
public:
    int minDistance(string s, string rev) {
        int maxi = max(s.size(), rev.size());
        vector<int> dp(maxi + 1, 0);
        for (int i = s.size() - 1; i >= 0; i--) {
            vector<int> curr(maxi + 1, 0);
            for (int j = rev.size() - 1; j >= 0; j--) {
                if (s[i] == rev[j])
                    curr[j] = dp[j + 1] + 1;
                else {
                    curr[j] = max(curr[j + 1], dp[j]);
                }
            }
            dp = curr;
        }
        return s.size() + rev.size() - 2 * dp[0];
    }
};