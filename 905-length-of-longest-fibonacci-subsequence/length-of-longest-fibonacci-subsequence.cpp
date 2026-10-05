class Solution {
public:
    int solve(int prev1, int prev2, vector<int>& nums, vector<vector<int>>& dp,
              unordered_map<int, int>& mp) {

        if (dp[prev1][prev2] != -1)
            return dp[prev1][prev2];

        int next = nums[prev1] + nums[prev2];

        if (mp.find(next) == mp.end())
            return dp[prev1][prev2] = 0;

        int nextIndex = mp[next];

        return dp[prev1][prev2] = 1 + solve(prev2, nextIndex, nums, dp, mp);
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[arr[i]] = i;
        }

        vector<vector<int>> dp(n, vector<int>(n, -1));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len = 2 + solve(i, j, arr, dp, mp);

                ans = max(ans, len);
            }
        }

        return ans >= 3 ? ans : 0;
    }
};