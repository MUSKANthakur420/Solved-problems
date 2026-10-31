#define mod 1000000007
class Solution {
public:
    vector<vector<int>> dp;
    int solve(int indx, int end, int fuel, vector<int>& arr) {
        if (indx == arr.size() || fuel < 0)
            return 0;
        if (dp[indx][fuel] != -1)
            return dp[indx][fuel];
        int ans = (indx == end) ? 1 : 0;
        for (int i = 0; i < arr.size(); i++) {
            if (i != indx) {
                int rfuel = fuel - abs(arr[indx] - arr[i]);
                if (rfuel >= 0) {
                    ans = (ans + solve(i, end, rfuel, arr)) % mod;
                }
            }
        }
        return dp[indx][fuel] = ans;
    }
    int countRoutes(vector<int>& arr, int start, int finish, int fuel) {
        dp.assign(102, vector<int>(203, -1));
        return solve(start, finish, fuel, arr);
    }
};