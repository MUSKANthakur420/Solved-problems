class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> mp;
    int solve(int indx, int d, vector<int>& arr) {
        if (d == 0 && indx == arr.size())
            return 0;
        if (indx > arr.size() || d < 0)
            return 1e9;
        if (dp[indx][d] != -1)
            return dp[indx][d];
        int ans = 1e9;
        for (int j = indx; j < arr.size(); j++) {
            ans = min(ans, mp[indx][j] + solve(j + 1, d - 1, arr));
        }
        return dp[indx][d] = ans;
    }
    int minDifficulty(vector<int>& arr, int d) {
        dp.assign(arr.size() + 1, vector<int>(d + 1, -1));
        mp.assign(arr.size() + 1, vector<int>(arr.size() + 1, 0));
        for (int i = 0; i < arr.size(); i++) {
            int maxele = arr[i];
            for (int j = i; j < arr.size(); j++) {
                maxele = max(maxele, arr[j]);
                mp[i][j] = maxele;
            }
        }
        int ans = solve(0, d, arr);
        if (ans == 1e9)
            return -1;
        return ans;
    }
};