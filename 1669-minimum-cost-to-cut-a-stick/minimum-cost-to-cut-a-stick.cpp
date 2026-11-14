class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, vector<int>& cuts) {
        if (i + 1 == j)
            return 0;
        int ans = 1e9;
        for (int k = i + 1; k < j; k++) {
            ans = min(ans, cuts[j] - cuts[i] + solve(i, k, cuts) +
                               solve(k, j, cuts));
        }
        return ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        dp.assign(cuts.size() + 1, vector<int>(cuts.size() + 1, 0));
        for (int i = cuts.size() - 2; i >= 0; i--) {
            for (int j = i + 2; j <= cuts.size() - 1; j++) {
                int ans = 1e9;
                for (int k = i + 1; k < j; k++) {
                    ans = min(ans, cuts[j] - cuts[i] + dp[i][k] + dp[k][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][cuts.size() - 1];
    }
};