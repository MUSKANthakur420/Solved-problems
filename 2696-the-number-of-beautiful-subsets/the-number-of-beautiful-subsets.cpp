class Solution {
public:
    int result = 0;
    int solve(int indx, int k, int prev, vector<vector<int>>& dp,
              vector<pair<int, int>>& mp) {
        if (indx >= mp.size()) {
            return 1;
        }
        if (dp[indx][prev] != -1)
            return dp[indx][prev];
        int notake = solve(indx + 1, k, 0, dp, mp);
        int ways = (1 << mp[indx].second) - 1;
        int x = mp[indx].first;
        int take = 0;
        if (!prev || indx == 0 || x - k != mp[indx - 1].first) {
            take = ways * solve(indx + 1, k, 1, dp, mp);
        }
        return dp[indx][prev] = take + notake;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> mp;
        for (auto it : nums) {
            mp[it % k].push_back(it);
        }
        int ans = 1;
        for (auto [rem, v] : mp) {
            sort(v.begin(), v.end());
            vector<pair<int, int>> arr;
            for (int x : v) {
                if (arr.empty() || arr.back().first != x) {
                    arr.push_back({x, 1});
                } else
                    arr.back().second++;
            }
            vector<vector<int>> dp(arr.size() + 1, vector<int>(2, -1));
            ans *= solve(0, k, 0, dp, arr);
        }
        return ans - 1;
    }
};