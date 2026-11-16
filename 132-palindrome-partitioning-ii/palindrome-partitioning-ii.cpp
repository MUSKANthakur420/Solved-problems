class Solution {
public:
    vector<int> dp;
    vector<vector<int>> pal;
    int solve(int i, string& s) {
        if (i == s.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int res = 1e9;
        for (int k = i; k < s.size(); k++) {
            if (pal[i][k] == 1) {
                res = min(res, 1 + solve(k + 1, s));
            }
        }
        return dp[i] = res;
    }
    int minCut(string s) {
        dp.assign(s.size() + 1, -1);
        pal.assign(s.size() + 1, vector<int>(s.size() + 1, 0));
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j] && (j - i <= 1 || pal[i + 1][j - 1])) {
                    pal[i][j] = 1;
                }
            }
        }
        return solve(0, s) - 1;
    }
};