class Solution {
public:
    int solve(int i, int j, vector<int>& cuts) {
        if (i > j)
            return 0;
        int mini = 1e9;
        for (int k = i; k <= j; k++) {
            int cost = cuts[j + 1] - cuts[i - 1] + solve(i, k - 1, cuts) +
                       solve(k + 1, j, cuts);
            mini = min(mini, cost);
        }
        return mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int size = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(size + 2, vector<int>(size + 2, 0));
        for (int i = size; i >= 1; i--) {
            for (int j = 1; j <= size; j++) {
                int mini = 1e9;
                if (i > j)
                    continue;
                for (int k = i; k <= j; k++) {
                    int cost =
                        cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][size];
    }
};