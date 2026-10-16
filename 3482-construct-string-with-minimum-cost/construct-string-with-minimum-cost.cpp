
class Solution {
public:
    const long long INF = 1e18;

    struct Node {
        int next[26];
        int fail;
        int out;
        int len;
        long long cost;

        Node() {
            fill(next, next + 26, -1);
            fail = 0;
            out = -1;
            len = 0;
            cost = 1e18;
        }
    };

    vector<Node> trie;

    void insert(const string& word, int cost) {
        int node = 0;

        for (char c : word) {
            int x = c - 'a';

            if (trie[node].next[x] == -1) {
                int newNode = trie.size();
                trie[node].next[x] = newNode;

                Node temp;
                temp.len = trie[node].len + 1;
                trie.push_back(temp);
            }

            node = trie[node].next[x];
        }

        trie[node].cost = min(trie[node].cost, (long long)cost);
    }

    void build() {
        queue<int> q;

        for (int c = 0; c < 26; c++) {
            int child = trie[0].next[c];

            if (child != -1) {
                trie[child].fail = 0;
                trie[child].out = -1;
                q.push(child);
            } else {
                trie[0].next[c] = 0;
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            int f = trie[u].fail;

            if (trie[f].cost < INF)
                trie[u].out = f;
            else
                trie[u].out = trie[f].out;

            for (int c = 0; c < 26; c++) {
                int v = trie[u].next[c];

                if (v != -1) {
                    trie[v].fail = trie[f].next[c];
                    q.push(v);
                } else {
                    trie[u].next[c] = trie[f].next[c];
                }
            }
        }
    }

    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        trie.clear();
        trie.emplace_back();

        for (int i = 0; i < words.size(); i++)
            insert(words[i], costs[i]);

        build();

        int n = target.size();
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        int node = 0;

        for (int i = 0; i < n; i++) {
            node = trie[node].next[target[i] - 'a'];

            int cur = node;

            while (cur != -1) {
                if (trie[cur].cost < INF) {
                    int len = trie[cur].len;

                    if (dp[i + 1 - len] != INF) {
                        dp[i + 1] =
                            min(dp[i + 1], dp[i + 1 - len] + trie[cur].cost);
                    }
                }

                cur = trie[cur].out;
            }
        }

        return dp[n] == INF ? -1 : (int)dp[n];
    }
};
