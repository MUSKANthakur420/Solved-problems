class Solution {
public:
    int solve(int i, vector<int>& nums, int k, int op1, int op2,
              vector<vector<vector<int>>>& dp) {
        if (i == nums.size())
            return 0;
        if (op1 < 0 && op2 < 0)
            return 0;
        if (dp[i][op1][op2] != -1)
            return dp[i][op1][op2];
        int a = 1e9, b = 1e9, c = 1e9;
        if (op1 > 0 && op2 > 0) {
            if (nums[i] >= k)
                a = min(a, (nums[i] - k + 1) / 2) +
                    solve(i + 1, nums, k, op1 - 1, op2 - 1, dp);
            if ((nums[i] + 1) / 2 >= k) {
                a = min(a, (nums[i] + 1) / 2 - k) +
                    solve(i + 1, nums, k, op1 - 1, op2 - 1, dp);
            }
        }
        if (op1 > 0) {
            int val = (nums[i] + 1) / 2;
            b = val + solve(i + 1, nums, k, op1 - 1, op2, dp);
        }
        if (nums[i] >= k && op2 > 0) {
            c = (nums[i] - k) + solve(i + 1, nums, k, op1, op2 - 1, dp);
        }
        int d = nums[i] + solve(i + 1, nums, k, op1, op2, dp);
        return dp[i][op1][op2] = min({a, b, c, d});
    }
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        vector<vector<vector<int>>> dp(
            nums.size() + 1,
            vector<vector<int>>(op1 + 1, vector<int>(op2 + 1, -1)));
        return solve(0, nums, k, op1, op2, dp);
    }
};