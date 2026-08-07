class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> prefix(nums.size(), 0);
        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = max(prefix[i - 1], nums[i]);
        }
        int minindx = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int minval = INT_MAX;
            for (int j = i; j < nums.size(); j++) {
                minval = min(minval, nums[j]);
            }
            if (prefix[i] - minval <= k)
                minindx = min(minindx, i);
        }
        return minindx == INT_MAX ? -1 : minindx;
    }
};