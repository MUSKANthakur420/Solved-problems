class Solution {
public:
    vector<int> prefix;
    vector<vector<int>> dp, hp;
    int h(int i, int k, int m, int n) {
        if (i > n)
            return -1e9;
        if (hp[i][k] != -1e9)
            return hp[i][k];
        int ans = h(i + 1, k, m, n);
        int next = solve(i, k - 1, m, n);
        if (next != -1e9)
            ans = max(ans, prefix[i] + next);
        return hp[i][k] = ans;
    }
    int solve(int indx, int k, int m, int n) {
        if (k == 0)
            return 0;
        if ((n - indx) < k * m)
            return -1e9;
        if (dp[indx][k] != -1e9)
            return dp[indx][k];
        int ans = solve(indx + 1, k, m, n);
        if (indx + m <= n) {
            int best = h(indx + m, k, m, n);
            if (best != -1e9)
                ans = max(ans, best - prefix[indx]);
        }
        return dp[indx][k] = ans;
    }
    int maxSum(vector<int>& nums, int k, int m) {
        int n = nums.size();
        prefix.assign(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];
        dp.assign(n + 2, vector<int>(k + 1, -1e9));
        hp.assign(n + 2, vector<int>(k + 1, -1e9));
        return solve(0, k, m, n);
    }
};