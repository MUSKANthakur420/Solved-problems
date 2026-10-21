class Solution {
public:
    vector<vector<unordered_map<int, int>>> dp;
    int solve(int indx, int j, vector<int>& nums, vector<int>& val,
              int currAnd) {
        if (j == val.size() && indx == nums.size())
            return 0;
        if (j >= val.size() || indx >= nums.size())
            return 1e9;
        if (dp[indx][j].count(currAnd))
            return dp[indx][j][currAnd];
        int sum = 1e9;
        if ((currAnd & nums[indx]) == val[j]) {
            sum = min(sum, nums[indx] + solve(indx + 1, j + 1, nums, val,
                                              (1 << 20) - 1));
        }
        int nsum = solve(indx + 1, j, nums, val, currAnd & nums[indx]);

        return dp[indx][j][currAnd] = min(sum, nsum);
    }
    int minimumValueSum(vector<int>& nums, vector<int>& val) {
        dp.assign(nums.size() + 1, vector<unordered_map<int, int>>(10));
        int ans = solve(0, 0, nums, val, (1 << 20) - 1);
        return ans == 1e9 ? -1 : ans;
    }
};