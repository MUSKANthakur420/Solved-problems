class Solution {
public:
    int give(int k, int val, vector<int>& nums) {
        int sum = 0;
        int maxi = INT_MIN;
        for (auto it : nums) {
            if (it == k)
                sum--;
            if (it == val)
                sum++;
            if (sum < 0)
                sum = 0;
            maxi = max(maxi, sum);
        }
        return maxi;
    }
    int maxFrequency(vector<int>& nums, int k) {
        map<int, int> mp;
        for (auto it : nums) {
            mp[it]++;
        }
        int maxi = 0;
        for (auto it : mp) {
            maxi = max(maxi, give(k, it.first, nums));
        }
        return maxi + mp[k];
    }
};