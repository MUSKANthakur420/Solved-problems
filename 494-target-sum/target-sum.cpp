class Solution {
public:
    int cnt = 0;
    void solve(int indx, vector<int>& nums, int t, long long s) {
        if (indx == nums.size()) {
            if (s == t)
                cnt++;
            return;
        }
        solve(indx + 1, nums, t, s + nums[indx]);
        solve(indx + 1, nums, t, s - nums[indx]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        solve(0, nums, target, 0LL);
        return cnt;
    }
};