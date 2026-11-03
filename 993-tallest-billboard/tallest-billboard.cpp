class Solution {
public:
    vector<vector<int>> dp;
    int solve(int indx, int diff, vector<int>& rods) {
        if (indx == rods.size()) {
            if (diff == 0)
                return 0;
            return -1e9;
        }
        if (dp[indx][diff + 5000] != -1)
            return dp[indx][diff + 5000];
        int notake = solve(indx + 1, diff, rods);
        int take = rods[indx] + solve(indx + 1, diff + rods[indx], rods);
        int take1 = rods[indx] + solve(indx + 1, diff - rods[indx], rods);
        return dp[indx][diff + 5000] = max({take, take1, notake});
    }
    int tallestBillboard(vector<int>& rods) {
        dp.assign(rods.size() + 1, vector<int>(10001, -1));
        return solve(0, 0, rods) / 2;
    }
};