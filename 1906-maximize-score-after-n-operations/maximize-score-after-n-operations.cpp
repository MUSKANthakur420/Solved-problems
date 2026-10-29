class Solution {
public:
    vector<int> dp;
    int gcd(int a, int b) {
        while (b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }

    int solve(int mask, int k, vector<int>& nums) {
        if (k > (nums.size() / 2))
            return 0;
        int n = nums.size();
        if (dp[mask] != -1)
            return dp[mask];
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i))
                continue;
            for (int j = i + 1; j < n; j++) {
                if (mask & (1 << j))
                    continue;
                int nmask = (mask | (1 << i) | (1 << j));
                int ans = k * gcd(nums[i], nums[j]) + solve(nmask, k + 1, nums);
                dp[mask] = max(dp[mask], ans);
            }
        }
        return dp[mask];
    }

    int maxScore(vector<int>& nums) {
        dp.assign(1 << 14, -1);
        return solve(0, 1, nums);
    }
};