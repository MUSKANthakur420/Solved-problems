class Solution {
public:
    int solve(int i, int j, int moves, vector<vector<int>>& arr,
              vector<vector<int>>& dp, vector<int>& drow, vector<int>& dcol) {
        int m = arr.size();
        int n = m;
        if (i == m - 1 && j == n - 1)
            return 0;
        if (moves >= n - 1 || i == j)
            return -1e9;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = -1e9;
        for (int k = 0; k < 3; k++) {
            int dx = drow[k] + i;
            int dy = dcol[k] + j;
            if (dx >= 0 && dx < m && dy >= 0 && dy < n) {
                ans = max(ans, arr[i][j] + solve(dx, dy, moves + 1, arr, dp,
                                                 drow, dcol));
            }
        }
        return dp[i][j] = ans;
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int sum = 0;
        int m = fruits.size();
        int n = m;
        for (int i = 0; i < n; i++) {
            sum += fruits[i][i];
        }
        vector <vector < int >> dp(n + 1, vector<int>(n + 1, -1));
        vector<int> drow = {1, 1, 1};
        vector<int> dcol = {-1, 0, 1};
        int b = solve(0, n - 1, 0, fruits, dp, drow, dcol);
        dp = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
        vector<int> drow1 = {-1, 0, 1};
        vector<int> dcol1 = {1, 1, 1};
        int c = solve(n - 1, 0, 0, fruits, dp, drow1, dcol1);
        return sum + b + c;
    }
};