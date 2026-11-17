#define mod 1000000007
class Solution {
public:
    vector<long long> fact;
    vector<long long> invfact;
    long long solve(long long a) {
        if (a == 1)
            return 1;
        if (fact[a] != 0)
            return fact[a];
        return fact[a] = 1LL * a % mod * solve(a - 1) % mod;
    }
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1)
                res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }
    long long give(int n, int r) {
        if (r > n)
            return 0;
        return (1LL * fact[n] % mod * invfact[n - r] % mod * invfact[r] % mod) %
               mod;
    }
    int minMaxSums(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        fact.assign(nums.size() + 1, 0);
        fact[1] = 1;
        fact[0] = 1;
        invfact.assign(nums.size() + 1, 0);
        solve(n);
        invfact[n] = power(fact[n], mod - 2);
        for (int i = n - 1; i >= 0; i--) {
            invfact[i] = (invfact[i + 1] * (i + 1)) % mod;
        }
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < k; j++) {
                long long mini = 1LL * nums[i] * give(i, j) % mod;
                long long maxi = 1LL * nums[i] * give(n - i - 1, j) % mod;
                ans = (ans + maxi + mini) % mod;
            }
        }
        return ans;
    }
};