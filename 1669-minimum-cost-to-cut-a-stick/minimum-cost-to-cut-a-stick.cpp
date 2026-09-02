class Solution {
public:
    int solve(int i, int j, vector<int>& cuts) {
        if (i > j)
            return 0;
        int maxi = 1e9;
        for (int k = i; k <= j; k++) {
            int cost = cuts[j + 1] - cuts[i - 1] + solve(i, k - 1, cuts) +
                       solve(k + 1, j, cuts);
            maxi = min(maxi, cost);
        }
        return maxi;
    }
    int minCost(int n, vector<int>& cuts) {
        int size = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(size + 2, vector<int>(size + 2, 0));
        for (int i = size; i >= 1; i--) {
            for (int j = 1; j <= size; j++) {
                if (i > j)
                    continue;
                int maxi = 1e9;
                for (int k = i; k <= j; k++) {
                    int cost =
                        cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j];
                    maxi = min(maxi, cost);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][size];
    }
};