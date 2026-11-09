class Solution {
public:
    unordered_map<string, int> dp;
    bool solve(string s, string t) {
        if (s == t)
            return true;
        if (s.size() != t.size())
            return false;
        string s2 = s;
        string t1 = t;
        sort(s2.begin(), s2.end());
        sort(t1.begin(), t1.end());
        if (s2 != t1)
            return false;
        string ans = s + '*' + t;
        if (dp.count(ans))
            return dp[ans];
        for (int k = 1; k < s.size(); k++) {
            bool ns = solve(s.substr(0, k), t.substr(0, k)) &&
                      solve(s.substr(k), t.substr(k));
            bool s1 = solve(s.substr(0, k), t.substr(s.size() - k)) &&
                      solve(s.substr(k), t.substr(0, s.size() - k));
            if (ns || s1)
                return dp[ans] = true;
        }
        return dp[ans] = false;
    }
    bool isScramble(string s1, string s2) { return solve(s1, s2); }
};