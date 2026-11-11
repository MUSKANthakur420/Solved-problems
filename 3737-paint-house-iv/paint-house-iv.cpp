class Solution {
public:
    int N;
    vector<vector<vector<long long>>> dp;

    long long solve(int i, int p1, int p2, vector<vector<int>>& cost) {

        if (i == N / 2)
            return 0;

        if (dp[i][p1][p2] != -1)
            return dp[i][p1][p2];

        long long ans = 1e15;
        int k = N - 1 - i;

        for (int col = 0; col < 3; col++) {
            if (col == p1)
                continue;

            for (int ncol = 0; ncol < 3; ncol++) {
                if (ncol == p2 || ncol == col)
                    continue;

                ans = min(ans, 1LL * cost[i][col] + cost[k][ncol] +
                                   solve(i + 1, col, ncol, cost));
            }
        }

        return dp[i][p1][p2] = ans;
    }

    long long minCost(int n, vector<vector<int>>& cost) {
        N = n;
        dp.assign(n / 2,
                  vector<vector<long long>>(4, vector<long long>(4, -1)));

        return solve(0, 3, 3, cost);
    }
};