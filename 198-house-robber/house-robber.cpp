class Solution {
public:
    vector<int> dp;
    int solve(int i, vector<int>& nums) {
        if (i >= nums.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int notake = solve(i + 1, nums);
        int take = nums[i] + solve(i + 2, nums);
        return dp[i] = max(take, notake);
    }
    int rob(vector<int>& nums) {
        dp.assign(nums.size() + 1, -1);
        return solve(0, nums);
    }
};