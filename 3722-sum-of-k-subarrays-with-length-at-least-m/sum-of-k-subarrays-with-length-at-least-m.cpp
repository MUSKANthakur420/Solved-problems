class Solution {
public:
    int maxSum(vector<int>& nums, int K, int m) {
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(K + 1, -1e9));
        vector<vector<int>> best(n + 1, vector<int>(K + 1, -1e9));

        dp[0][0] = 0;

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];

        for (int i = 1; i <= n; i++) {
            for (int k = 0; k <= K; k++) {

                dp[i][k] = dp[i - 1][k];

                if (k > 0) {
                    best[i][k] = best[i - 1][k] + nums[i - 1];

                    if (i >= m) {
                        best[i][k] =
                            max(best[i][k],
                                dp[i - m][k - 1] + prefix[i] - prefix[i - m]);
                    }

                    dp[i][k] = max(dp[i][k], best[i][k]);
                }
            }
        }

        return dp[n][K];
    }
};