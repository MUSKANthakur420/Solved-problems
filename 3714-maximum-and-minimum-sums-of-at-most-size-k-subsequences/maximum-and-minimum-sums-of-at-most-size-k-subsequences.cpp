#define mod 1000000007
class Solution {
public:
    long long power(long long a, long long b) {
        long long ans = 1;

        while (b > 0) {
            if (b & 1)
                ans = ans * a % mod;

            a = a * a % mod;
            b >>= 1;
        }

        return ans;
    }
    void inverse(vector<long long>& inv) {
        int n = inv.size() - 1;
        inv[n] = power(inv[n], mod - 2);
        for (int i = n; i >= 1; i--)
            inv[i - 1] = 1LL * inv[i] * i % mod;
    }
    void cal(vector<long long>& facto) {
        for (int i = 1; i < facto.size(); i++)
            facto[i] = (1LL * i % mod * facto[i - 1] % mod) % mod;
    }
    long long give(vector<long long>& facto, vector<long long>& inv, int n,
                   int r) {
        if (r > n)
            return 0;
        return 1LL * facto[n] * inv[n - r] % mod * inv[r] % mod;
    }
    int minMaxSums(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(), nums.end());
        vector<long long> facto(nums.size() + 1, 1);
        vector<long long> inv(nums.size() + 1, 1);
        int n = nums.size();
        cal(facto);
        inv[n] = facto[n];
        inverse(inv);
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int size = 1; size <= k; size++) {
                long long mini = 1LL * nums[i] % mod *
                                 give(facto, inv, n - i - 1, size - 1) % mod;
                long long maxi =
                    1LL * nums[i] % mod * give(facto, inv, i, size - 1) % mod;
                ans = (ans % mod + mini % mod + maxi % mod) % mod;
            }
        }
        return ans;
    }
};