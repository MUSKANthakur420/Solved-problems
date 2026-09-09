class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        vector<int> res(nums.begin(), nums.end());
        for (auto it : nums)
            res.push_back(it);
        long long int l = 0LL, r = 0LL;
        for (int i = 0; i < nums.size(); i++) {
            if (i < nums.size() / 2)
                l += nums[i];
            else
                r += nums[i];
        }
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (l > r)
                cnt++;
            l = l + res[nums.size() / 2 + i] - nums[i];
            r = r - res[nums.size() / 2 + i] + nums[i];
        }
        return cnt;
    }
};