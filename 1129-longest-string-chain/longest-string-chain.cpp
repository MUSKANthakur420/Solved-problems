class Solution {
public:
    static bool comp(const string& a, const string& b) {
        return a.size() < b.size();
    }
    int solve(int indx, int prev, vector<string>& words) {
        if (indx == words.size())
            return 0;
        int take = 0, notake = 0;
        if (prev == -1) {
            take = 1 + solve(indx + 1, indx, words);
        }
        if (prev != -1 && words[indx].size() == words[prev].size() + 1) {
            string forward = words[indx];
            string back = words[prev];
            int n = words[indx].size();
            int i = 0, j = 0, cnt = 0;
            while (i < n && j < words[prev].size()) {
                if (forward[i] == back[j]) {
                    i++;
                    j++;
                } else {
                    cnt++;
                    i++;
                }
            }
            if (cnt + (n - i) == 1)
                take = 1 + solve(indx + 1, indx, words);
        }
        notake = solve(indx + 1, prev, words);
        return max(take, notake);
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        vector<int> dp(words.size() + 1, 0);
        for (int indx = words.size() - 1; indx >= 0; indx--) {
            vector<int> curr(words.size() + 1, 0);
            for (int prev = indx - 1; prev >= -1; prev--) {
                int take = 0, notake = 0;
                if (prev == -1)
                    take = 1 + dp[indx + 1];
                if (prev != -1 &&
                    words[indx].size() == words[prev].size() + 1) {
                    string forward = words[indx];
                    string back = words[prev];
                    int n = words[indx].size();
                    int i = 0, j = 0, cnt = 0;
                    while (i < n && j < words[prev].size()) {
                        if (forward[i] == back[j]) {
                            i++;
                            j++;
                        } else {
                            cnt++;
                            i++;
                        }
                    }
                    if (cnt + (n - i) == 1)
                        take = 1 + dp[indx + 1];
                }
                notake = dp[prev + 1];
                curr[prev + 1] = max(take, notake);
            }
            dp = curr;
        }
        return dp[0];
    }
};