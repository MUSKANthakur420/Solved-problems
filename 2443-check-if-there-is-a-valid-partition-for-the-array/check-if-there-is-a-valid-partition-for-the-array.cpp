class Solution {
public:
    bool solve(int indx, vector<vector<int>>& help, vector<int>& dp) {
        if (indx == dp.size()) {
            return true;
        }
        if (dp[indx] != -1)
            return dp[indx];
        if (indx + 1 < dp.size() && help[indx][0] == 2) {
            if (solve(indx + 2, help, dp))
                return dp[indx] = true;
        }
        if (indx + 2 < dp.size() && help[indx][1] == 3) {
            if (solve(indx + 3, help, dp))
                return dp[indx] = true;
        }
        return dp[indx] = false;
    }
    bool validPartition(vector<int>& nums) {
        vector<vector<int>> help(nums.size() + 1, vector<int>(2, 0));
        for (int i = 0; i < nums.size(); i++) {
            if (i + 1 < nums.size()) {
                if (nums[i] == nums[i + 1]) {
                    help[i][0] = 2;
                }
            }
            if (i + 2 < nums.size()) {
                if (nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2] ||
                    nums[i] + 1 == nums[i + 1] &&
                        nums[i + 1] + 1 == nums[i + 2]) {
                    help[i][1] = 3;
                }
            }
        }
        vector<int> dp(nums.size(), -1);
        return solve(0, help, dp);
    }
};