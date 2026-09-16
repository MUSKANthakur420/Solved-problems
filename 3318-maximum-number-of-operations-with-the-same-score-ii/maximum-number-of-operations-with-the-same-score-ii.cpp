class Solution {
public:
    int solve(int l, int r, int n, int t, vector<int>& nums,
              vector<vector<int>>& dp) {
        if (l > r)
            return 0;
        int maxi = 0;
        if (dp[l][r] != -1)
            return dp[l][r];
        if ((l + 1) <= r && (nums[l] + nums[l + 1] == t)) {
            maxi = max(maxi, 1 + solve(l + 2, r, n, t, nums, dp));
        }
        if (l < r && (nums[l] + nums[r] == t)) {
            maxi = max(maxi, 1 + solve(l + 1, r - 1, n, t, nums, dp));
        }
        if (r - 1 >= l && (nums[r] + nums[r - 1] == t)) {
            maxi = max(maxi, 1 + solve(l, r - 2, n, t, nums, dp));
        }
        return dp[l][r] = maxi;
    }
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        int a = nums[0] + nums[1];
        int b = nums[0] + nums[n - 1];
        int c = nums[n - 1] + nums[n - 2];
        vector<vector<int>> dp1(n, vector<int>(n, -1));
        vector<vector<int>> dp2(n, vector<int>(n, -1));
        vector<vector<int>> dp3(n, vector<int>(n, -1));
        int maxi = 0;
        maxi = max(maxi, solve(0, n - 1, n, a, nums, dp1));
        maxi = max(maxi, solve(0, n - 1, n, b, nums, dp2));
        maxi = max(maxi, solve(0, n - 1, n, c, nums, dp3));
        return maxi;
    }
};