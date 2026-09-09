class Solution {
public:
    int solve(string s) {
        int cnt = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1])
                cnt++;
        }
        return cnt;
    }
    int countRotations(string s, int k) {
        string curr = s;
        int ans = 0;
        for (int i = 0; i < curr.size(); i++) {
            curr.push_back(curr[0]);
            curr.erase(curr.begin() + 0);
            if (solve(curr) == k) {
                ans++;
            }
        }
        return ans;
    }
};