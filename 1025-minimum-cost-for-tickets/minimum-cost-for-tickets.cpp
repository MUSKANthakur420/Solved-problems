class Solution {
public:
    int solve(int indx, vector<int>& days, vector<int>& costs,
              vector<int>& dp) {
        if (indx == days.size())
            return 0;
        if (dp[indx] != -1)
            return dp[indx];
        int x = 1e9, y = 1e9, z = 1e9;
        int p1 = lower_bound(days.begin(), days.end(), days[indx] + 1) -
                 days.begin();
        int p2 = lower_bound(days.begin(), days.end(), days[indx] + 7) -
                 days.begin();
        int p3 = lower_bound(days.begin(), days.end(), days[indx] + 30) -
                 days.begin();
        x = costs[0] + solve(p1, days, costs, dp);
        y = costs[1] + solve(p2, days, costs, dp);
        z = costs[2] + solve(p3, days, costs, dp);
        return dp[indx] = min({x, y, z});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, -1);
        int maxi = *max_element(days.begin(), days.end());
        return solve(0, days, costs, dp);
    }
};