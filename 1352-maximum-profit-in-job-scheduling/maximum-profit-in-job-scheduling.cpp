class Solution {
public:
    vector<int> dp;
    static bool comp(const pair<int, pair<int, int>>& a,
                     const pair<int, pair<int, int>>& b) {
        return a.second.first < b.second.first;
    }
    int solve(int indx, vector<pair<int, pair<int, int>>>& p,
              vector<int>& profit) {
        if (indx == profit.size())
            return 0;
        if (dp[indx] != -1)
            return dp[indx];
        int notake = solve(indx + 1, p, profit);
        int low = indx + 1;
        int high = profit.size() - 1;
        int newindx = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (p[mid].second.first >= p[indx].second.second) {
                newindx = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        int take = p[indx].first;
        if (newindx != -1)
            take += solve(newindx, p, profit);
        return dp[indx] = max(take, notake);
    }
    int jobScheduling(vector<int>& st, vector<int>& end, vector<int>& profit) {
        vector<pair<int, pair<int, int>>> p;
        for (int i = 0; i < st.size(); i++) {
            p.push_back({profit[i], {st[i], end[i]}});
        }
        sort(p.begin(), p.end(), comp);
        dp.assign(st.size() + 1, -1);
        return solve(0, p, profit);
    }
};