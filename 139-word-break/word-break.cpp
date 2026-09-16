class Solution {
public:
    bool solve(int indx, vector<string>& arr, string& s, vector<int>& dp) {
        if (indx == s.length())
            return true;
        if (dp[indx] != -1)
            return dp[indx];
        for (auto it : arr) {
            if (s.substr(indx, it.length()) == it) {
                if (solve(indx + it.length(), arr, s, dp))
                    return true;
            }
        }
        return dp[indx] = false;
    }
    bool wordBreak(string s, vector<string>& arr) {
        vector<int> dp(s.size() + 1, -1);
        return solve(0, arr, s, dp);
    }
};