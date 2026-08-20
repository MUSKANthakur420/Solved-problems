class Solution {
public:
    int solve(int indx, vector<int>& nums, int t, long long s,
              vector<vector<int>>& dp, int off) {
        if (indx == nums.size()) {
            if (s == t)
                return 1;
        }
        if (indx < nums.size() && dp[indx][s + off] != -1)
            return dp[indx][s + off];
        int take = 0, notake = 0;
        if (indx < nums.size()) {
            take = solve(indx + 1, nums, t, s + nums[indx], dp, off);
            notake = solve(indx + 1, nums, t, s - nums[indx], dp, off);
        }
        return dp[indx][s + off] = take + notake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {

        int off = 0;
        for (auto it : nums) {
            off += abs(it);
        }
        if (abs(target) > off)
            return 0;
        vector<int> dp(2 * off + 1, 0);
        dp[target + off] = 1;
        for (int indx = nums.size() - 1; indx >= 0; indx--) {
            vector<int> curr(2 * off + 1, 0);
            for (int sum = -off; sum <= off; sum++) {
                long long take = 0, notake = 0;
                if (sum - nums[indx] >= -off)
                    notake = dp[sum - nums[indx] + off];
                if (sum + nums[indx] <= off)
                    take = dp[(sum + nums[indx] + off)];
                curr[sum + off] = take + notake;
            }
            dp = curr;
        }
        return dp[off];
    }
};