class Solution {
public:
    int solve(int indx, vector<int>& nums, int sum, int prod,
              vector<vector<int>>& dp) {
        if (indx == nums.size()) {
            if (sum == prod)
                return 0;
            return 1e9;
        }
        if (sum < prod)
            return 1e9;
        if (dp[indx][prod] != -1)
            return dp[indx][prod];
        int notake = solve(indx + 1, nums, sum, prod, dp);
        int prev = nums[indx];
        int steps = 0;
        int takem = 1e9;
        while (prev + prod <= sum) {
            takem =
                min(takem, steps + solve(indx + 1, nums, sum, prod + prev, dp));
            prev *= 2;
            steps++;
        }
        prev = nums[indx];
        int taked = 1e9;
        steps = 0;
        while (prev > 1) {
            prev = floor(prev / 2);
            steps++;
            takem =
                min(takem, steps + solve(indx + 1, nums, sum, prod + prev, dp));
        }
        return dp[indx][prod] = min({taked, takem, notake});
    }
    int minOperations(vector<int>& nums, int sum) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(sum + 1, -1));
        int x = solve(0, nums, sum, 0, dp);
        if (x == 1e9)
            return -1;
        return x;
    }
};