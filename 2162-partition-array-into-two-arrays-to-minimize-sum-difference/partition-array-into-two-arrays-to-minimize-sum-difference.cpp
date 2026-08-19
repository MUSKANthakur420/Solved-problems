class Solution {
public:
    void solve(int indx, int n, int size, vector<vector<int>>& res,
               vector<int>& nums, int sum) {
        if (indx == n) {
            res[size].push_back(sum);
            return;
        }
        solve(indx + 1, n, size + 1, res, nums, nums[indx] + sum);
        solve(indx + 1, n, size, res, nums, sum);
    }
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        int total = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> left(n + 1);
        vector<vector<int>> right(n + 1);
        solve(0, n, 0, left, nums, 0);
        solve(n, nums.size(), 0, right, nums, 0);
        for (int i = 0; i <= n; i++)
            sort(right[i].begin(), right[i].end());
        int ans = INT_MAX;
        for (int k = 0; k <= n; k++) {
            int remain = n - k;
            for (auto l : left[k]) {
                   double target = (double)total / 2.0 - l;
                auto it =
                    lower_bound(right[remain].begin(), right[remain].end(), target);
                // double target = (double)total / 2.0 - l;
                if (it != right[remain].end()) {
                    int selectedSum = l + *it;
                    ans = min(ans, abs(total - 2 * selectedSum));
                }
                if (it != right[remain].begin()) {
                    --it;

                    int selectedSum = l + *it;
                    ans = min(ans, abs(total - 2 * selectedSum));
                }
            }
        }
        return ans;
    }
};