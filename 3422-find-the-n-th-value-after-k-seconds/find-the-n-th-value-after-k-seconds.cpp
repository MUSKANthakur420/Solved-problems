#define mod 1000000007
class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<int> prev(n + 1, 1), curr(n + 1, 1);
        for (int time = 1; time <= k; time++) {
            for (int i = 1; i < n; i++) {
                curr[i] = (curr[i - 1] + prev[i]) % mod;
            }
            prev = curr;
        }
        return curr[n - 1];
    }
};