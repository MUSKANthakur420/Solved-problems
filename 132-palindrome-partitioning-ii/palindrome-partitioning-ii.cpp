class Solution {
public:
    bool ispal(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
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
            int mini = 1e9;
            for (int j = i; j < s.size(); j++) {
                int cost = 0;
                if (pal[i][j]) {
                    cost = 1 + dp[j + 1];
                    mini = min(mini, cost);
                }
            }
            dp[i] = mini;
        }
        return dp[0] - 1;
    }
};