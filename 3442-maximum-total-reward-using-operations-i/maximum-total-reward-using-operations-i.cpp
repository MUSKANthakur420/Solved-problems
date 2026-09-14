class Solution {
public:
    long long solve(int val, vector<int>& arr, vector<long long>& dp) {

        if (dp[val] != -1)
            return dp[val];

        long long ans = 0;

        int i = upper_bound(arr.begin(), arr.end(), val) - arr.begin();

        for (int j = i; j < arr.size(); j++) {
            ans = max(ans, (long long)arr[j] + solve(val + arr[j], arr, dp));
        }

        return dp[val] = ans;
    }

    int maxTotalReward(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int acc = accumulate(arr.begin(), arr.end(), 0);

        vector<long long> dp(acc + 1, -1);

        return solve(0, arr, dp);
    }
};