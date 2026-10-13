#define mod 1000000007
class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> dp(maxi + 1, 0);
        vector<int> sum(maxi + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            dp[nums[i]] = (dp[nums[i]] + 1) % mod;
            sum[nums[i]] = (sum[nums[i]] + nums[i]) % mod;
            if (nums[i] - 1 >= 0) {
                dp[nums[i]] = (dp[nums[i]] + dp[nums[i] - 1]) % mod;
                sum[nums[i]] = (sum[nums[i]] + sum[nums[i] - 1] +
                                (1LL * nums[i] * dp[nums[i] - 1])%mod) %
                               mod;
            }
            if (nums[i] + 1 <= maxi) {
                dp[nums[i]] = (dp[nums[i]] + dp[nums[i] + 1]) % mod;
                sum[nums[i]] = (sum[nums[i]] + sum[nums[i] + 1] +
                                (1LL * nums[i] * dp[nums[i] + 1])%mod) %
                               mod;
            }
        }
        long long ans = 0;
        for (auto it : sum) {
            ans = (ans + it) % mod;
        }
        return ans;
    }
};