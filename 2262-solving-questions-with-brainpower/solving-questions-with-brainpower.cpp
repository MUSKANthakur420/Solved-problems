class Solution {
public:
    long long solve(int indx, vector<vector<int>>& arr, vector<long long>& dp) {
        if (indx >= arr.size())
            return 0LL;
        long long take = 0LL, notake = 0LL;
        if (dp[indx] != -1)
            return dp[indx];
        notake = solve(indx + 1, arr, dp);
        take = arr[indx][0] + solve(indx + arr[indx][1] + 1, arr, dp);
        return dp[indx] = max(take, notake);
    }
    long long mostPoints(vector<vector<int>>& arr) {
        vector<long long> dp(arr.size() + 1, -1LL);
        return solve(0, arr, dp);
    }
};