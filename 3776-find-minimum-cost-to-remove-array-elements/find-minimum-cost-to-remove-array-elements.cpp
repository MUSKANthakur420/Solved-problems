class Solution {
public:
    int solve(int indx, int prev, vector<int>& nums, vector<vector<int>>& dp,
              int n) {
        if (indx == n)
            return nums[prev];
        if (indx == n - 1)
            return max(nums[prev], nums[indx]);
        if (dp[indx][prev] != -1)
            return dp[indx][prev];
        int take = min({max(nums[indx], nums[prev]) +
                            solve(indx + 2, indx + 1, nums, dp, n),
                        max(nums[prev], nums[indx + 1]) +
                            solve(indx + 2, indx, nums, dp, n),
                        max(nums[indx], nums[indx + 1]) +
                            solve(indx + 2, prev, nums, dp, n)});
        return dp[indx][prev] = take;
    }
    int minCost(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return solve(1, 0, nums, dp, nums.size());
    }
};