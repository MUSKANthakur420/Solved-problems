class Solution {
public:
    vector<vector<int>> dp;
    int solve(int indx, int prev, vector<int>& nums) {
        if (indx + 1 >= nums.size()) {
            return max(nums[indx], nums[prev]);
        }
        if (dp[indx][prev] != -1)
            return dp[indx][prev];
        int t1 = max(nums[prev], nums[indx]) + solve(indx + 2, indx + 1, nums);
        int t2 = max(nums[prev], nums[indx + 1]) + solve(indx + 2, indx, nums);
        int t3 = max(nums[indx], nums[indx + 1]) + solve(indx + 2, prev, nums);
        return dp[indx][prev] = min({t1, t2, t3});
    }
    int minCost(vector<int>& nums) {
        if (nums.size() <= 2) {
            return *max_element(nums.begin(), nums.end());
        }
        dp.assign(nums.size() + 1, vector<int>(nums.size() + 1, -1));
        return solve(1, 0, nums);
    }
};