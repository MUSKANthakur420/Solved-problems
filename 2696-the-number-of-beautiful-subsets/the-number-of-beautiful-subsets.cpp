class Solution {
public:
    int result = 0;
    void solve(int indx, int k, vector<int>& nums, vector<int>& dp,
               unordered_map<int, int>& mp) {
        if (indx == nums.size()) {
            result++;
            return;
        }
        solve(indx + 1, k, nums, dp, mp);
        if (mp.find(nums[indx] - k) == mp.end() &&
            mp.find(nums[indx] + k) == mp.end()) {
            mp[nums[indx]]++;
            solve(indx + 1, k, nums, dp, mp);
            mp[nums[indx]]--;
            if (mp[nums[indx]] == 0)
                mp.erase(nums[indx]);
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> dp(nums.size() + 1, -1);
        unordered_map<int, int> mp;
        solve(0, k, nums, dp, mp);
        return result - 1;
    }
};