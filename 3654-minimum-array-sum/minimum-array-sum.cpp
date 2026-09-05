class Solution {
public:
    int solve(int i, vector<int>& nums, int k, int op1, int op2,
              vector<vector<vector<int>>>& dp) {
        if (i == nums.size())
            return 0;
        int a = 1e9, b = 1e9, c = 1e9;
        if (dp[i][op1][op2] != -1)
            return dp[i][op1][op2];
        if (op1 > 0 && op2 > 0) {
            if (nums[i] >= k) {
                int x1 = (nums[i] - k + 1) / 2;
                a = min(a, x1);
            }
            int half = (nums[i] + 1) / 2;
            if (half >= k) {
                int x2 = half - k;
                a = min(a, x2);
            }

            if (a != 1e9)
                a += solve(i + 1, nums, k, op1 - 1, op2 - 1, dp);
        }
        if (op1 > 0) {
            b = (nums[i] + 1) / 2 + solve(i + 1, nums, k, op1 - 1, op2, dp);
        }
        if (op2 > 0 && nums[i] >= k) {
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