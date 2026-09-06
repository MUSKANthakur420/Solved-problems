class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1])
                dp[i] += dp[i + 1];
        }
        int maxi = 1;
        for (int i = 0; i < dp.size(); i++) {
            if (dp[i] > 2 && dp[i] % 2 == 0) {
                maxi = max(maxi, dp[i] / 2);
            }
            if (dp[i] > 2 && dp[i] % 2 == 1)
                maxi = max(maxi, (dp[i] - 1) / 2);
            if (i + dp[i] < dp.size())
                maxi = max(maxi, min(dp[i], dp[i + dp[i]]));
        }
        return maxi;
    }
};