#define mod 1000000007
class Solution {
public:
    vector<int> dp;

    int solve(int indx, string& res, int k) {
        if (indx == res.size())
            return 1;
        if (dp[indx] != -1)
            return dp[indx];
        int ans = 0;
        long long temp = 0;
        for (int i = indx; i < res.size(); i++) {
            temp = temp * 10 + (res[i] - '0');
            if (temp > k)
                break;
            if (res[indx] != '0')
                ans = (ans + solve(i + 1, res, k)) % mod;
        }
        return dp[indx] = ans % mod;
    }
    int numberOfArrays(string s, int k) {
        dp.assign(s.size() + 1, -1);
        return solve(0, s, k);
    }
};