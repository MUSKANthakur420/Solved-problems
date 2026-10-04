class Solution {
public:
    int alice = 0;
    int solve(int indx, int m, vector<int>& arr, vector<vector<int>>& dp) {
        if (indx >= arr.size())
            return 0;
        if (m <= 100 && dp[indx][m] != -1)
            return dp[indx][m];
        int take = INT_MIN;
        int total = 0;
        for (int j = indx; j < arr.size(); j++)
            total += arr[j];
        for (int i = 1; i <= 2 * m; i++) {
            if (indx + i - 1 < arr.size())
                take = max(take, total - solve(indx + i, max(m, i), arr, dp));
        }
        return dp[indx][m] = take;
    }
    int stoneGameII(vector<int>& piles) {
        vector<vector<int>> dp(piles.size() + 1, vector<int>(110, -1));
        return solve(0, 1, piles, dp);
    }
};