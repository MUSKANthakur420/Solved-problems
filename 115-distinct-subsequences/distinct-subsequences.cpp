class Solution {
public:
    map<string, int> mp;
    int solve(int i, int j, string& a, string& b, vector<vector<int>>& dp) {
        if (j == b.size())
            return 1;
        if (i == a.size() || j == b.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (a[i] == b[j]) {
            return solve(i + 1, j + 1, a, b, dp) + solve(i + 1, j, a, b, dp);
        } else
            return solve(i + 1, j, a, b, dp);
        return dp[i][j] = 0;
    }
    int numDistinct(string a, string b) {
        vector<long long int> dp(b.size() + 1, 0LL);
        dp[b.size()] = 1;
        for (int i = a.size() - 1; i >= 0; i--) {
            vector<long long int> curr(b.size() + 1, 0LL);
            curr[b.size()] = 1;
            for (int j = b.size() - 1; j >= 0; j--) {
                if (a[i] == b[j]) {
                    curr[j] = (dp[j + 1] % INT_MAX + dp[j] % INT_MAX) % INT_MAX;
                } else
                    curr[j] = dp[j];
            }
            dp = curr;
        }
        return dp[0];
    }
};