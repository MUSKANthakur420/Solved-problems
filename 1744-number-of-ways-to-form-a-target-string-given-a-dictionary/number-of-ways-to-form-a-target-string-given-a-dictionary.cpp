#define mod 1000000007
class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> freq;
    // int solve(int indx, int k, vector<string>& words, string& target) {
    //     if (indx == target.size())
    //         return 1;
    //     if (dp[indx][k] != -1)
    //         return dp[indx][k];
    //     long long ans = 0;
    //     for (int j = k; j < n; j++) {
    //         if (freq[j][target[indx] - 'a'] != 0) {
    //             ans = (ans + (1LL * freq[j][target[indx] - 'a'] *
    //                           solve(indx + 1, j + 1, words, target)) %
    //                              mod) %
    //                   mod;
    //         }
    //     }
    //     return dp[indx][k] = ans;
    // }
    int numWays(vector<string>& words, string target) {
        int n = words[0].size();
        dp.assign(target.size() + 1, vector<int>(n + 1, 0));
        freq.assign(n + 1, vector<int>(27, 0));
        for (string it : words) {
            for (int j = 0; j < it.size(); j++) {
                freq[j][it[j] - 'a']++;
            }
        }
        for (int k = 0; k <= n; k++)
            dp[target.size()][k] = 1;
        for (int indx = target.size() - 1; indx >= 0; indx--) {
            for (int k = n - 1; k >= 0; k--) {
                long long ans = 0;
                dp[indx][k] =
                    (dp[indx][k + 1] + 1LL * freq[k][target[indx] - 'a'] *
                                           dp[indx + 1][k + 1] % mod) %
                    mod;
            }
        }
        return dp[0][0];
    }
};