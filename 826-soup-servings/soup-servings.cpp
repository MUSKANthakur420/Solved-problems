class Solution {
public:
    double solve(int n, int a, int b, vector<vector<double>>& dp) {
        if (a == 0 && b > a)
            return 1;
        if (a == 0 && b == 0)
            return 0.5;
        if (b <= 0 && a > 0)
            return 0;
        if (dp[a][b] != -1)
            return dp[a][b];
        double ans = 0.0;
        int a1 = (a - 100) >= 0 ? (a - 100) : 0;
        int a2 = (a - 75) >= 0 ? (a - 75) : 0;
        int a3 = (a - 50) >= 0 ? (a - 50) : 0;
        int a4 = (a - 25) >= 0 ? (a - 25) : 0;
        int b2 = (b - 25) >= 0 ? (b - 25) : 0;
        int b3 = (b - 50) >= 0 ? (b - 50) : 0;
        int b4 = (b - 75) >= 0 ? (b - 75) : 0;
        ans += solve(n, a1, b, dp) / 4.0;
        ans += solve(n, a2, b2, dp) / 4.0;
        ans += solve(n, a3, b3, dp) / 4.0;
        ans += solve(n, a4, b4, dp) / 4.0;
        return dp[a][b] = ans;
    }
    double soupServings(int n) {
        vector<vector<double>> dp(4799, vector<double>(4799, -1));
        if (n >= 4800)
            return 1;
        return solve(n, n, n, dp);
    }
};