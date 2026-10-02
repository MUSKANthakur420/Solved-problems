class Solution {
public:
    int solve(int i, vector<int>& arr, vector<int>& dp) {
        if (i == arr.size()) {
            return 0;
        }
        if (dp[i] != -1)
            return dp[i];
        int take1 = INT_MIN, take2 = INT_MIN, take3 = INT_MIN;
        take1 = arr[i] - solve(i + 1, arr, dp);
        if (i + 1 < arr.size())
            take2 = arr[i] + arr[i + 1] - solve(i + 2, arr, dp);
        if (i + 2 < arr.size())
            take3 = arr[i] + arr[i + 1] + arr[i + 2] - solve(i + 3, arr, dp);
        return dp[i] = max({take1, take2, take3});
    }
    string stoneGameIII(vector<int>& arr) {
        int size = arr.size();
        vector<int> dp(size + 1, 0);
        dp[size] = 0;
        for (int i = size - 1; i >= 0; i--) {
            int take1 = INT_MIN, take2 = INT_MIN, take3 = INT_MIN;
            take1 = arr[i] - dp[i + 1];
            if (i + 1 < arr.size())
                take2 = arr[i] + arr[i + 1] - dp[i + 2];
            if (i + 2 < arr.size())
                take3 = arr[i] + arr[i + 1] + arr[i + 2] - dp[i + 3];
            dp[i] = max({take1, take2, take3});
        }
        if (dp[0] == 0)
            return "Tie";
        if (dp[0] < 0)
            return "Bob";
        return "Alice";
    }
};