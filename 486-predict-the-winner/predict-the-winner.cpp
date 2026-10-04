class Solution {
public:
    int solve(int start, int end, vector<int>& nums, vector<vector<int>>& dp) {
        if (start == nums.size() || end < start)
            return 0;
        if (dp[start][end] != -1)
            return dp[start][end];
        int x = nums[start] - solve(start + 1, end, nums, dp);
        int y = nums[end] - solve(start, end - 1, nums, dp);
        return dp[start][end] = max(x, y);
    }
    bool predictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(22, vector<int>(22, -1));
        int ans = solve(0, nums.size() - 1, nums, dp);
        if (ans >= 0)
            return true;
        return false;
    }
};