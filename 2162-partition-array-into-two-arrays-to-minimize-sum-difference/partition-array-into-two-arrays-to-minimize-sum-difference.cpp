class Solution {
public:
    void solve(int indx, int n, int s, vector<int>& nums,
               vector<vector<int>>& res, int sum) {
        if (indx == n) {
            res[s].push_back(sum);
            return;
        }
        solve(indx + 1, n, s + 1, nums, res, sum + nums[indx]);
        solve(indx + 1, n, s, nums, res, sum);
    }
    int minimumDifference(vector<int>& nums) {
        int t = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size() / 2;
        vector<vector<int>> left(n + 1);
        vector<vector<int>> right(n + 1);
        solve(0, n, 0, nums, left, 0);
        solve(n, nums.size(), 0, nums, right, 0);
        for (int i = 0; i <= n; i++) {
            sort(right[i].begin(), right[i].end());
        }
        int mini = INT_MAX;
        for (int k = 0; k <= n; k++) {
            int remain = n - k;
            for (auto l : left[k]) {
                double target = (double)t / 2.0 - l;
                auto it = lower_bound(right[remain].begin(),
                                      right[remain].end(), target);
                if (it != right[remain].end()) {
                    int sum = l + *it;
                    mini = min(mini, abs(2 * sum - t));
                }
                if (it != right[remain].begin()) {
                    --it;
                    int sum = l + *it;
                    mini = min(mini, abs(2 * sum - t));
                }
            }
        }
        return mini;
    }
};