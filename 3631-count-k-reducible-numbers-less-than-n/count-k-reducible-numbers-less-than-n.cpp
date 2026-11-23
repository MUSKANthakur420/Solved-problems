#define mod 1000000007
class Solution {
public:
    vector<int> dp;
    vector<vector<vector<int>>> mp;
    int solve(int indx, int tight, int bits, int k, string& s) {
        if (indx == s.size())
            return ((bits > 0) && (1 + dp[bits]) <= k) ? 1 : 0;
        if (mp[indx][tight][bits] != -1)
            return mp[indx][tight][bits];
        int cnt = 0;
        if (tight == 1) {
            if (s[indx] == '0')
                cnt=solve(indx + 1, 1, bits, k, s);
            else {
                cnt = (solve(indx + 1, 0, bits, k, s) % mod +
                       solve(indx + 1, 1, bits + 1, k, s) % mod) %
                      mod;
            }
        } else {
            cnt = (solve(indx + 1, 0, bits, k, s) +
                   solve(indx + 1, 0, bits + 1, k, s)) %
                  mod;
        }
        return mp[indx][tight][bits] = cnt % mod;
    }
    int countKReducibleNumbers(string s, int k) {
        dp.assign(801, 0);
        mp.assign(s.size() + 1, vector<vector<int>>(2, vector<int>(801, -1)));
        for (int i = 2; i <= 800; i++) {
            dp[i] = 1 + dp[__builtin_popcount(i)];
        }
        int ans = solve(0, 1, 0, k, s);
        int cnt = 0;
        for (auto it : s) {
            if (it == '1')
                cnt++;
        }
        if (cnt > 0 && dp[cnt] + 1 <= k)
            ans = (ans + mod - 1) % mod;
        return ans;
    }
};