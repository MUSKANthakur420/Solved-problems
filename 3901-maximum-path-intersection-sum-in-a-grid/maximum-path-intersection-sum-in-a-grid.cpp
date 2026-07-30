class Solution {
public:
    int solve(vector<int>& a) {
        int n = a.size();
        if (n < 2)
            return INT_MIN;

        int pref = a[0];
        int minPref = 0;
        int best = INT_MIN;

        for (int i = 1; i < n; i++) {
            pref += a[i];

            best = max(best, pref - minPref);

            minPref = min(minPref, pref - a[i]);
        }

        return best;
    }

    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int ans = INT_MIN;
        for (int i = 0; i < m; i++) {
            vector<int> row = grid[i];
            ans = max(ans, solve(row));
        }
        for (int j = 0; j < n; j++) {
            vector<int> col;
            for (int i = 0; i < m; i++)
                col.push_back(grid[i][j]);

            ans = max(ans, solve(col));
        }
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                ans = max(ans, grid[i][j]);
            }
        }

        return ans;
    }
};