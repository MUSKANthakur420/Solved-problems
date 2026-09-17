class Solution {
public:
    string res = "";
    int solve(int indx, string& s, vector<string>& arr, vector<int>& dp) {
        if (indx == s.size())
            return 0;
        if (dp[indx] != -1)
            return dp[indx];
        int take = 0, notake = 0;
        notake = solve(indx + 1, s, arr, dp);
        for (auto it : arr) {
            if (s.substr(indx, it.length()) == it) {
                take = max(take, (int)it.length() +
                                     solve(indx + it.length(), s, arr, dp));
            }
        }
        return dp[indx] = max(take, notake);
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int> dp(s.size() + 1, -1);
        int val = solve(0, s, dictionary, dp);
        return s.size() - val;
    }
};