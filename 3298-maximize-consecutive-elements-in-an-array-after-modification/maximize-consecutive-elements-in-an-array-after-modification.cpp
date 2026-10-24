class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(1e6 + 1, 0);
        for (auto it : nums) {
            dp[it + 1] = dp[it] + 1;
            dp[it] = dp[it - 1] + 1;
        }
        return *max_element(dp.begin(), dp.end());
    }
};