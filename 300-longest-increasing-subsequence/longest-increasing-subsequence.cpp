class Solution {
public:
    vector<vector<int>> dp;
    int solve(int indx, int prev, vector<int>& nums) {
        if (indx == nums.size())
            return 0;
        if (dp[indx][prev + 1] != -1)
            return dp[indx][prev + 1];
        int notake = solve(indx + 1, prev, nums);
        int take = 0;
        if (prev == -1 || nums[indx] > nums[prev]) {
            take = 1 + solve(indx + 1, indx, nums);
        }
        return dp[indx][prev + 1] = max(take, notake);
    }
    int lengthOfLIS(vector<int>& nums) {
        dp.assign(nums.size() + 1, vector<int>(nums.size() + 2, -1));
        return solve(0, -1, nums);
    }
};