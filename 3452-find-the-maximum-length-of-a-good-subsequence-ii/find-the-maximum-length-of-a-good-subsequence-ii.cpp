class Solution {
public:
    int solve(int indx, int prev, int k, vector<int>& nums,
              vector<vector<vector<int>>>& dp) {
        if (k < 0)
            return -1e9;
        if (indx == nums.size()) {
            return 0;
        }
        if (dp[indx][prev + 1][k] != -1)
            return dp[indx][prev + 1][k];
        int notake = solve(indx + 1, prev, k, nums, dp);
        int take = 0;
        if (prev == -1 || indx >= 0 && prev >= 0) {
            int val = 0;
            if (prev != -1)
                val = (nums[prev] == nums[indx]) ? 0 : -1;
            take = 1 + solve(indx + 1, indx, k + val, nums, dp);
        }
        return dp[indx][prev + 1][k] = max(take, notake);
    }
    int maximumLength(vector<int>& nums, int k) {
        unordered_map<int, unordered_map<int, int>> dp;
        vector<int> maxdp(k + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            for (int v = k; v >= 0; v--) {
                dp[nums[i]][v] =
                    max(1 + dp[nums[i]][v], (v > 0 ? maxdp[v - 1] + 1 : 0));
                maxdp[v] = max(maxdp[v], dp[nums[i]][v]);
            }
        }
        return *max_element(maxdp.begin(), maxdp.end());
    }
};