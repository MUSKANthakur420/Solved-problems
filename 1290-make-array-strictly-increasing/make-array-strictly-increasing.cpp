class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(int i, int prev, bool isa, vector<int>& a, vector<int>& b) {
        if (i == a.size())
            return 0;
        if (!isa && (prev >= b.size()))
            return 1e9;
        if (dp[i][prev + 1][isa] != -1)
            return dp[i][prev + 1][isa];
        int take = 1e9;
        if (prev == -1) {
            take = min(take, min(solve(i + 1, i, true, a, b),
                                 1 + solve(i + 1, 0, false, a, b)));
        } else if (isa && (a[i] > a[prev]) || !isa && (a[i] > b[prev])) {
            int indx =
                (isa) ? upper_bound(b.begin(), b.end(), a[prev]) - b.begin()
                      : upper_bound(b.begin(), b.end(), b[prev]) - b.begin();
            take = min(take, solve(i + 1, i, true, a, b));
            if (indx != b.size())
                take = min(take, 1 + solve(i + 1, indx, false, a, b));
        } else {
            int indx =
                (isa) ? upper_bound(b.begin(), b.end(), a[prev]) - b.begin()
                      : upper_bound(b.begin(), b.end(), b[prev]) - b.begin();
            if (indx != b.size()) {
                take = min(take, 1 + solve(i + 1, indx, false, a, b));
            }
        }
        return dp[i][prev + 1][isa] = take;
    }
    int makeArrayIncreasing(vector<int>& a, vector<int>& b) {
        set<int> st;
        for (auto it : b)
            st.insert(it);
        vector<int> B(st.begin(), st.end());
        dp.assign(a.size() + 1,
                  vector<vector<int>>(max((int)a.size() + 2, (int)b.size() + 2),
                                      vector<int>(2, -1)));
        int ans = solve(0, -1, true, a, B);
        if (ans == 1e9)
            return -1;
        return ans;
    }
};