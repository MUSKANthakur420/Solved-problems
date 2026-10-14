#define mod 1000000007
class Solution {
public:
    int solve(int indx, int tight, int bits, string& s,
              vector<vector<vector<int>>>& dp, vector<int>& form, int k) {
        if (indx == s.size()) {
            return (bits > 0 && (form[bits] + 1) <= k) ? 1 : 0;
        }
        int res = 0;
        if (dp[indx][tight][bits] != -1)
            return dp[indx][tight][bits];
        if (tight == 1) {
            if (s[indx] == '0') {
                res = solve(indx + 1, 1, bits, s, dp, form, k);
            } else {
                res = (solve(indx + 1, 1, bits + 1, s, dp, form, k) +
                       solve(indx + 1, 0, bits, s, dp, form, k)) %
                      mod;
            }
        } else {
            res = (solve(indx + 1, 0, bits + 1, s, dp, form, k) +
                   solve(indx + 1, 0, bits, s, dp, form, k)) %
                  mod;
        }
        return dp[indx][tight][bits] = res;
    }
    int countKReducibleNumbers(string s, int k) {
        vector<int> form(801, 0);
        vector<vector<vector<int>>> dp(
            801, vector<vector<int>>(2, vector<int>(801, -1)));
        for (int i = 2; i <= 800; i++) {
            form[i] = (1 + form[__builtin_popcount(i)]) % mod;
        }
        int ans = solve(0, 1, 0, s, dp, form, k);

        int bits = 0;
        for (char c : s) {
            if (c == '1')
                bits++;
        }

        if (bits > 0 && form[bits] + 1 <= k)
            ans = (ans - 1 + mod) % mod;

        return ans;
    }
};