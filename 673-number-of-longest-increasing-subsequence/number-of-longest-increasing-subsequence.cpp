class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        vector<int> dp(arr.size() + 1, 1);
        vector<int> cnt(arr.size() + 1, 1);
        int maxi = 1;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < i; j++) {
                int take = 0, notake = 0;
                if (arr[i] > arr[j] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j];
                } else if (arr[i] > arr[j] && dp[j] + 1 == dp[i])
                    cnt[i] += cnt[j];
            }
            maxi = max(maxi, dp[i]);
        }
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (dp[i] == maxi)
                ans += cnt[i];
        }
        return ans;
    }
};