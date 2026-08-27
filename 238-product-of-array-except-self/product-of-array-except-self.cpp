class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<long long> prefix(nums.size());
        vector<long long> suffix(nums.size());
        prefix[0] = (nums[0] == 0) ? 1 : nums[0];
        suffix[nums.size() - 1] =
            (nums[nums.size() - 1] == 0) ? 1 : nums[nums.size() - 1];
        int cnt = 0;
        if (nums[0] == 0)
            cnt++;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == 0) {
                prefix[i] = prefix[i - 1];
                suffix[nums.size() - i - 1] = suffix[nums.size() - i];
                cnt++;
            } else {
                prefix[i] = prefix[i - 1] * nums[i];
                suffix[nums.size() - i - 1] =
                    suffix[nums.size() - i] * ((nums[nums.size() - i - 1] == 0)
                                                   ? 1
                                                   : nums[nums.size() - i - 1]);
            }
        }
        vector<int> ans(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if ((cnt - 1) == 0)
                    ans[i] = 1LL * prefix[i] * suffix[i];
            } else if (nums[i] != 0 && cnt == 0)
                ans[i] = 1LL * (prefix[i] / nums[i]) * (suffix[i] / nums[i]);
            // cout << suffix[i] << " ";
        }
        return ans;
    }
};