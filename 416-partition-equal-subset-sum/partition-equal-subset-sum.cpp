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
        vector<vector<int>> dp(nums.size() + 1, vector<int>(sum + 1, 0));
        dp[nums.size()][sum / 2] = 1;
        for (int indx = nums.size() - 1; indx >= 0; indx--) {
            for (int d = 0; d <= sum; d++) {
                int notake = dp[indx + 1][d];
                int take = 0;
                if (nums[indx] + d <= sum) {
                    take = dp[indx + 1][nums[indx] + d];
                }
                dp[indx][d] = take || notake;
            }
        }
        return dp[0][0];
    }
};