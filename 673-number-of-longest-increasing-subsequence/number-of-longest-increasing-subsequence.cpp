class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp1(nums.size(), 1);
        vector<int> cnt(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] > nums[i] && (1 + dp1[i]) > dp1[j]) {
                    dp1[j] = 1 + dp1[i];
                    cnt[j] = cnt[i];
                } else if ((1 + dp1[i]) == dp1[j]) {
                    cnt[j] += cnt[i];
                }
            }
        }
        int ans = 0;
        int maxlen = *max_element(dp1.begin(), dp1.end());
        for (int i = 0; i < dp1.size(); i++) {
            if (dp1[i] == maxlen)
                ans += cnt[i];
        }
        return ans;
    }
};