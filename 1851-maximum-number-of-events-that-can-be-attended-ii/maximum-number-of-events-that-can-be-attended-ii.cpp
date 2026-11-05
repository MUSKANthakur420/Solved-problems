class Solution {
public:
    vector<vector<int>> dp;
    static bool comp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    int solve(int indx, int k, vector<vector<int>>& arr) {
        if (k < 0)
            return -1e9;
        if (indx == arr.size()) {
            return 0;
        }
        if (dp[indx][k] != -1)
            return dp[indx][k];
        int notake = solve(indx + 1, k, arr);
        int take = -1e9;
        int idx = upper_bound(arr.begin(), arr.end(), arr[indx][1],
                              [](int x, const vector<int>& row) {
                                  return x < row[0];
                              }) -
                  arr.begin();
        if (k > 0) {
            if (idx != arr.size())
                take = arr[indx][2] + solve(idx, k - 1, arr);
            else
                take = arr[indx][2];
        }
        return dp[indx][k] = max(take, notake);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), comp);
        dp.assign(events.size() + 1, vector<int>(k + 1, -1));
        return solve(0, k, events);
    }
};