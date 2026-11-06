class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int mini = INT_MAX;
        for (int i = 0; (i + 1) < nums.size(); i += 2) {
            mini = min(mini,
                       (int)stoll(to_string(nums[i]) + to_string(nums[i + 1])));
        }
        return mini;
    }
};