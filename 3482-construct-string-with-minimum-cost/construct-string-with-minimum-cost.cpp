class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        const long long M1 = 1000000007, M2 = 1000000009, B = 131;
        int n = target.size();

        // prefix hashes of target
        vector<long long> h1(n + 1, 0), h2(n + 1, 0), p1(n + 1, 1),
            p2(n + 1, 1);
        for (int i = 0; i < n; i++) {
            int c = target[i] - 'a' + 1;
            h1[i + 1] = (h1[i] * B + c) % M1;
            h2[i + 1] = (h2[i] * B + c) % M2;
            p1[i + 1] = p1[i] * B % M1;
            p2[i + 1] = p2[i] * B % M2;
        }

        // for each word length: hash -> cheapest cost
        map<int, unordered_map<long long, int>> byLen;
        for (int k = 0; k < (int)words.size(); k++) {
            long long a = 0, b = 0;
            for (char ch : words[k]) {
                int c = ch - 'a' + 1;
                a = (a * B + c) % M1;
                b = (b * B + c) % M2;
            }
            auto& m = byLen[words[k].size()];
            long long key = a << 32 | b;
            if (!m.count(key) || m[key] > costs[k])
                m[key] = costs[k];
        }

        const long long INF = 1e18;
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (auto& [len, m] : byLen) {
                if (len > i)
                    break;
                if (dp[i - len] == INF)
                    continue;

                // hash of target[i-len .. i)
                long long a = ((h1[i] - h1[i - len] * p1[len]) % M1 + M1) % M1;
                long long b = ((h2[i] - h2[i - len] * p2[len]) % M2 + M2) % M2;

                auto it = m.find(a << 32 | b);
                if (it != m.end())
                    dp[i] = min(dp[i], dp[i - len] + it->second);
            }
        }

        return dp[n] == INF ? -1 : dp[n];
    }
};