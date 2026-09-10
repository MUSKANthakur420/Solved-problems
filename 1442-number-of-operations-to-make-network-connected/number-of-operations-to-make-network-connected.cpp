class disjointset {
    vector<int> parent, rank;

public:
    disjointset(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int findupar(int n) {
        if (n == parent[n])
            return n;
        return parent[n] = findupar(parent[n]);
    }
    void unionbyrank(int u, int v) {
        int ulp_u = findupar(u);
        int ulp_v = findupar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] == rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        } else if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else
            parent[ulp_v] = ulp_u;
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        disjointset ds(n);
        int extra = 0;
        for (auto it : connections) {
            int u = it[0], v = it[1];
            if (ds.findupar(u) == ds.findupar(v))
                extra++;
            else
                ds.unionbyrank(u, v);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (ds.findupar(i) == i)
                cnt++;
        }
        if (extra >= cnt - 1)
            return cnt - 1;
        return -1;
    }
};