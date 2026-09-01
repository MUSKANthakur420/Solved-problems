class Solution {
public:
    int solve(int i, int j, vector<int>& nums) {
        if (i > j)
            return 0;
        int maxi = -1e9;
        for (int k = i; k <= j; k++) {
            int cost = nums[i - 1] * nums[k] * nums[j + 1] +
                       solve(i, k - 1, nums) + solve(k + 1, j, nums);
            maxi = max(maxi, cost);
        }
        return maxi;
    }
    int maxCoins(vector<int>& nums) {
        int size = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size() + 1,
                               vector<int>(nums.size() + 1, 0));
        for (int i = nums.size() - 2; i >= 1; i--) {
            for (int j = 1; j <= nums.size() - 2; j++) {
                if (i > j)
                    continue;
                int maxi = -1e9;
                for (int k = i; k <= j; k++) {
                    int cost = nums[i - 1] * nums[k] * nums[j + 1] +
                               dp[i][k - 1] + dp[k + 1][j];
                    maxi = max(maxi, cost);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][nums.size() - 2];
    }
};