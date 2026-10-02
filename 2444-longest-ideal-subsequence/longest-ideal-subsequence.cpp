class Solution {
public:
    int solve(int indx, int prev, int k, string& s, vector<vector<int>>& dp) {
        if (indx == s.size())
            return 0;
        if (dp[s[indx] - 'a'][s[prev + 1] - 'a'] != -1)
            return dp[s[indx] - 'a'][s[prev + 1] - 'a'];
        int notake = solve(indx + 1, prev, k, s, dp);
        int take = 0;
        if (prev == -1 || abs((s[indx] - 'a') - (s[prev] - 'a')) <= k) {
            take = 1 + solve(indx + 1, indx, k, s, dp);
        }
        return dp[s[indx] - 'a'][s[prev + 1] - 'a'] = max(take, notake);
    }
    int longestIdealString(string s, int k) {
        // vector<int> dp(1e5 + 1, 0);
        // for (int i = s.size() - 1; i >= 0; i--) {
        //     vector<int> curr(1e5 + 1, 0);
        //     for (int j = i; j >= -1; j--) {
        //         int notake = dp[j + 1];
        //         int take = 0;
        //         if (j == -1 || abs((s[i] - 'a') - (s[j] - 'a')) <= k) {
        //             take = 1 + dp[i + 1];
        //         }
        //         curr[j + 1] = max(take, notake);
        //     }
        //     dp = curr;
        // }
        // optimize approach using character compression
        vector<int> dp(27, 0);
        for (auto it : s) {
            int best = 0;
            for (char c = 'a'; c <= 'z'; c++) {
                if (abs(it - c) <= k) {
                    best = max(best, dp[c - 'a']);
                }
            }
            dp[it - 'a'] = best + 1;
        }
        return *max_element(dp.begin(), dp.end());
    }
};