class Solution {
public:
    vector<vector<int>> dp;

    int solve(int indx, int k, string& s) {
        if (k < 0)
            return 1e9;

        if (indx == s.size())
            return 0;

        if (dp[indx][k] != -1)
            return dp[indx][k];

        int notake = solve(indx + 1, k - 1, s);

        int take = 1e9;
        int cnt = 0, delcount = 0;

        for (int i = indx; i < s.size(); i++) {
            if (s[i] == s[indx]) {
                cnt++;
            } else {
                delcount++;
            }

            if (delcount <= k) {
                int cost = (cnt == 1) ? 1 : 1 + to_string(cnt).size();

                take = min(take, cost + solve(i + 1, k - delcount, s));
            }
        }

        return dp[indx][k] = min(take, notake);
    }

    int getLengthOfOptimalCompression(string s, int k) {
        dp.assign(s.size(), vector<int>(k + 1, -1));
        return solve(0, k, s);
    }
};