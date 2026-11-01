#define mod 1000000007
class Solution {
public:
    vector<vector<int>> dp;
    int solve(int n, int song, int len, int goal, int k) {
        if (len == goal)
            return song == n;
        if (dp[song][len] != -1)
            return dp[song][len];
        long long notake =
            (1LL * solve(n, song + 1, len + 1, goal, k) * (n - song)) % mod;
        long long take =
            (1LL * solve(n, song, len + 1, goal, k) * max(0, song - k)) % mod;
        return dp[song][len] = (take + notake) % mod;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        dp.assign(101, vector<int>(101, -1));
        return solve(n, 0, 0, goal, k);
    }
};