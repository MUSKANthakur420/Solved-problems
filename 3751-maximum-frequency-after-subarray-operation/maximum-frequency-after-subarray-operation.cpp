class Solution {
public:
    unordered_map<int, int> mp;
    int K;
    // int give(int i, int j, vector<int>& nums, int val) {
    //     int cnt = 0;
    //     for (int x = i; x <= j; x++) {
    //         if (nums[x] == val)
    //             cnt++;
    //         if (nums[x] == K)
    //             cnt--;
    //     }
    //     return mp[K] + cnt;
    // }
    int give(int k, int val, vector<int>& nums) {
        int cnt = 0;
        int maxi = -1e9;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val)
                cnt++;
            if (nums[i] == k)
                cnt--;
            if (cnt < 0)
                cnt = 0;
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
    // int solve(int indx, int k, vector<int>& nums) {
    //     if (indx == nums.size())
    //         return 0;
    //     int notake = solve(indx + 1, k, nums);
    //     int take = -1e9;
    //     for (int j = indx; j < nums.size(); j++) {
    //         take = max(take, give(indx, j, nums, nums[j]));
    //     }
    //     return max(take, notake);
    // }
    int maxFrequency(vector<int>& nums, int k) {
        for (auto it : nums)
            mp[it]++;
        int ans = -1e9;
        for (auto it : mp) {
            ans = max(ans, give(k, it.first, nums));
        }
        return ans + mp[k];
    }
};