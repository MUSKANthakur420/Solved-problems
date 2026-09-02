class Solution {
public:
    bool ispal(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        return rev == s;
    }
    int minCut(string s) {
        vector<int> dp(s.size() + 1, 0);
        vector<vector<int>> pal(s.size() + 1, vector<int>(s.size() + 1, 0));

        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j] && (j - i <= 1 || pal[i + 1][j - 1])) {
                    pal[i][j] = 1;
                }
            }
        }

        for (int i = s.size() - 1; i >= 0; i--) {
            int minicut = 1e9;
            for (int j = i; j <= s.size() - 1; j++) {
                if (pal[i][j]) {
                    int cut;
                    if (j == s.size() - 1)
                        cut = 0;
                    else
                        cut = 1 + dp[j + 1];
                    minicut = min(minicut, cut);
                }
                // dp[j] = minicut;
            }
            dp[i] = minicut;
        }
        return dp[0];
    }
};