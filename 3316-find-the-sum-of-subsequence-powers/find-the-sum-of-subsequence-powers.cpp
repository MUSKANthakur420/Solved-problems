#define mod 1000000007
class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(int indx, int prev, int k, vector<int>& nums, int diff) {
        if (k == 0)
            return 1;
        if (nums.size() - indx < k)
            return 0;
        if (dp[indx][prev + 1][k] != -1)
            return dp[indx][prev + 1][k];
        int notake = solve(indx + 1, prev, k, nums, diff);
        int take = 0;
        if (prev == -1 || abs(nums[indx] - nums[prev]) >= diff) {
            take = solve(indx + 1, indx, k - 1, nums, diff);
        }
        return dp[indx][prev + 1][k] = (take + notake) % mod;
    }
    int sumOfPowers(vector<int>& nums, int k) {
        set<int> diff;
        vector<int> a = nums;
        sort(a.begin(), a.end());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                diff.insert(abs(a[j] - a[i]));
            }
        }
        long long ans = 0;
        for (auto it : diff) {
            dp.assign(
                nums.size() + 1,
                vector<vector<int>>(nums.size() + 2, vector<int>(k + 1, -1)));
            int cnt1 = solve(0, -1, k, a, it);
            dp.assign(
                nums.size() + 1,
                vector<vector<int>>(nums.size() + 2, vector<int>(k + 1, -1)));
            int cnt2 = solve(0, -1, k, a, it + 1);
            ans = (ans + 1LL * it * ((cnt1 - cnt2 + mod) % mod)) % mod;
        }
        return ans;
    }
};