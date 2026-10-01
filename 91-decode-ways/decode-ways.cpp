class Solution {
public:
    int solve(int i, int n, string& s, vector<int>& dp) {
        if (i == n)
            return 1;
        if (s[i] == '0')
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int ans = 0;
        string form = "";
        if (i + 1 < n)
            form = s.substr(i, 2);
        ans += solve(i + 1, n, s, dp);
        if (!form.empty() && 10 <= stoi(form) && stoi(form) <= 26) {
            ans += solve(i + 2, n, s, dp);
        }
        return dp[i] = ans;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1, -1);
        return solve(0, s.size(), s, dp);
    }
};