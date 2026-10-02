class Solution {
public:
    int solve(int t, vector<int>& nums, vector<int>& dp) {
        if (t == 0)
            return 1;
        if (dp[t] != -1)
            return dp[t];
        int ans = 0;
        for (auto it : nums) {
            if (it <= t) {
                ans += solve(t - it, nums, dp);
            }
        }
        return dp[t] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(1002, -1);
        return solve(target, nums, dp);
    }
};