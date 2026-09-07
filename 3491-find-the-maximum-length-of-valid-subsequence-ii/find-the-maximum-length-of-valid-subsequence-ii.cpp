class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans = INT_MIN;
        vector<vector<int>> dp(k + 1, vector<int>(k + 1, 0));
        for (int i = 0; i < nums.size(); i++) {
            for (int prev = 0; prev < k; prev++) {
                dp[nums[i] % k][prev] =
                    max(dp[nums[i] % k][prev], 1 + dp[prev][nums[i] % k]);
                ans = max(ans, dp[nums[i] % k][prev]);
            }
        }
        return ans;
    }
};