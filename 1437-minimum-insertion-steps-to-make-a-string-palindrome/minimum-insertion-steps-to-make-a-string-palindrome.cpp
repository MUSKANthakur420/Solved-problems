class Solution {
public:
    int minInsertions(string s) {
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
        return s.size() - dp[0];
    }
};