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
        vector<vector<int>> dp(nums.size(), vector<int>(sum + 1, -1));
        return solve(0, sum, 0, nums.size(), nums, dp);
    }
};