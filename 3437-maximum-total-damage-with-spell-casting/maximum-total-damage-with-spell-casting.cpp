class Solution {
public:
    long long solve(int i, int n, vector<int>& power, map<long long, int>& mp,
                    vector<long long>& dp) {
        if (i == n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        long long take = 1LL * mp[power[i]] * power[i], notake = 0;
        notake = solve(i + 1, n, power, mp, dp);
        auto it = lower_bound(power.begin() + i + 1, power.end(), power[i] + 3);
        int indx = it - power.begin();
        if (indx < n)
            take =
                1LL * mp[power[i]] * power[i] + solve(indx, n, power, mp, dp);
        return dp[i] = max(take, notake);
    }
    long long maximumTotalDamage(vector<int>& power) {
        map<long long, int> mp;
        for (auto it : power)
            mp[it]++;
        set<int> st(power.begin(), power.end());
        vector<int> npower(st.begin(), st.end());
        int n = npower.size();
        vector<long long> dp(npower.size() + 1, -1);
        for (int i = n - 1; i >= 0; i--) {
            long long take = 1LL * mp[npower[i]] * npower[i], notake = 0;
            notake = dp[i + 1];
            auto it = lower_bound(npower.begin() + i + 1, npower.end(),
                                  npower[i] + 3);
            int indx = it - npower.begin();
            if (indx < n)
                take = 1LL * mp[npower[i]] * npower[i] + dp[indx];
            dp[i] = max(take, notake);
        }
        return dp[0];
    }
};