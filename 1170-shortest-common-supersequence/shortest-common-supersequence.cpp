class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>> dp(str1.size() + 1,
                               vector<int>(str2.size() + 1, 0));
        for (int i = str1.size() - 1; i >= 0; i--) {
            for (int j = str2.size() - 1; j >= 0; j--) {
                if (str1[i] == str2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
        string ans = "";
        int i = 0, j = 0;
        while (i < str1.size() && j < str2.size()) {
            if (str1[i] == str2[j]) {
                ans += str1[i];
                i++;
                j++;
            } else {
                if (dp[i][j + 1] > dp[i + 1][j]) {
                    ans += str2[j];
                    j++;
                } else {
                    ans += str1[i];
                    i++;
                }
            }
        }
        while (i < str1.size())
            ans += str1[i++];
        while (j < str2.size())
            ans += str2[j++];
        return ans;
    }
};