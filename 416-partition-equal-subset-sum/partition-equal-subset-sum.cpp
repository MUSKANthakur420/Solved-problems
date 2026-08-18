class Solution {
public:
    int solve(int indx, int totalsum, int sum, int n, vector<int>& nums,
              vector<vector<int>>& dp) {
        if (totalsum == 2 * sum) {
            return 1;
        }
        if (indx == n)
            return 0;
        if (dp[indx][sum] != -1)
            return dp[indx][sum];
        int take = solve(indx + 1, totalsum, sum + nums[indx], n, nums, dp);
        int notake = solve(indx + 1, totalsum, sum, n, nums, dp);
        return dp[indx][sum] = take || notake;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0)
            return false;
        vector<int> dp(sum + 1, 0);
        dp[sum / 2] = 1;
        for (int indx = nums.size() - 1; indx >= 0; indx--) {
            vector<int> curr(sum + 1, 0);
            for (int d = 0; d <= sum/2; d++) {
                int notake = dp[d];
                int take = 0;
                if (nums[indx] + d <= sum) {
                    take = dp[nums[indx] + d];
                }
                curr[d] = take || notake;
            }
            dp = curr;
        }
        return dp[0];
    }
};