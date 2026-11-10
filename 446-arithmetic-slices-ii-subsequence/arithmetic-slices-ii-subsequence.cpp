class Solution {
public:
    vector<int> dp;
    int solve(int indx, long long diff, vector<int>& nums) {
        int ans = 0;
        if (dp[indx] != -1)
            return dp[indx];
        for (int i = indx + 1; i < nums.size(); i++) {
            if ((long long)nums[i] - nums[indx] == diff) {
                ans += 1 + solve(i, diff, nums);
            }
        }

        return dp[indx] = ans;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long diff = (long long)nums[j] - nums[i];
                dp.assign(n + 1, -1);
                ans += solve(j, diff, nums);
            }
        }

        return ans;
    }
};