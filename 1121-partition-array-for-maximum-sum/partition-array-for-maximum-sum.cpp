class Solution {
public:
    int solve(int i, vector<int>& arr, int k) {
        if (i == arr.size())
            return 0;
        int sum = -1e9;
        int maxi = 0;
        for (int j = i; j < arr.size(); j++) {
            maxi = max(maxi, arr[j]);
            int cost = 0;
            if (abs(j - i + 1) <= k) {
                cost = (j - i + 1) * maxi + solve(j + 1, arr, k);
            }
            sum = max(sum, cost);
        }
        return sum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size() + 1, 0);
        for (int i = arr.size() - 1; i >= 0; i--) {
            int maxi = 0, sum = -1e9;
            for (int j = i; j < arr.size(); j++) {
                maxi = max(maxi, arr[j]);
                int cost = 0;
                if (abs(j - i + 1) <= k) {
                    cost = (j - i + 1) * maxi + dp[j + 1];
                }
                sum = max(sum, cost);
            }
            dp[i] = sum;
        }
        return dp[0];
    }
};