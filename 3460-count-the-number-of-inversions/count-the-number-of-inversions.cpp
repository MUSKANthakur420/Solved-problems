#define mod 1000000007
class Solution {
public:
    int solve(int prefix, int cnt, int j, vector<vector<int>>& reqs,
              vector<vector<int>>& dp) {
        if (prefix == 0)
            return cnt == 0;
        if (j >= 0 && reqs[j][0] == prefix) {
            if (reqs[j][1] != cnt)
                return 0;
            --j;
        }
        int ans = 0;
        if (dp[prefix][cnt] != -1)
            return dp[prefix][cnt];
        for (int k = 0; k <= min(prefix, cnt); k++) {
            ans = (ans + solve(prefix - 1, cnt - k, j, reqs, dp)) % mod;
        }
        return dp[prefix][cnt] = ans;
    }
    int numberOfPermutations(int n, vector<vector<int>>& reqs) {
        sort(reqs.begin(), reqs.end());
        vector<vector<int>> dp(n + 1, vector<int>(401, -1));
        return solve(n - 1, reqs.back()[1], reqs.size() - 1, reqs, dp);
    }
};