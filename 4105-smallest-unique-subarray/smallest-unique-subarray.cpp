#define mod 1000000007
#define base 10007
class Solution {
public:
    bool check(vector<int>& nums, int mid) {
        map<long long, int> mp;
        long long hash = 0, power = 1;
        for (int i = 0; i < mid; i++) {
            hash = (hash * base + nums[i]) % mod;
            if (i < mid - 1)
                power = (power * base) % mod;
        }
        mp[hash] = 1;
        for (int j = mid; j < nums.size(); j++) {
            hash = (hash - nums[j - mid] * power % mod + mod) % mod;
            hash = (hash * base + nums[j]) % mod;
            mp[hash]++;
        }
        for (auto it : mp) {
            if (it.second == 1)
                return true;
        }
        return false;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int low = 1, high = nums.size();
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(nums, mid)) {
                high = mid - 1;
                ans = mid;
            } else
                low = mid + 1;
        }
        return ans;
    }
};