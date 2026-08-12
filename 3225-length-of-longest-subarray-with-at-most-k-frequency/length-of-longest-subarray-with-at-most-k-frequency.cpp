class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0, r = 0;
        map<int, int> mp;
        int maxi = INT_MIN;
        while (r < nums.size()) {
            mp[nums[r]]++;
            if (mp[nums[r]] > k) {
                while (mp[nums[r]] > k) {
                    mp[nums[l]]--;
                    l++;
                }
            } else
                maxi = max(maxi, r - l + 1);
            r++;
        }
        return maxi;
    }
};