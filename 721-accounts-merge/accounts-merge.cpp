class DisjointSet {
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUPar(int x) {
        if (x == parent[x])
            return x;

        return parent[x] = findUPar(parent[x]);
    }

    void unionByRank(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv)
            return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& arr) {
        map<string, int> mp;
        DisjointSet ds(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 1; j < arr[i].size(); j++) {
                if (mp.find(arr[i][j]) == mp.end())
                    mp[arr[i][j]] = i;
                else {
                    ds.unionByRank(mp[arr[i][j]], i);
                }
            }
        }
        set<string> st[arr.size()];
        for (auto it : mp) {
            st[ds.findUPar(it.second)].insert(it.first);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < arr.size(); i++) {
            if (ds.findUPar(i) != i)
                continue;
            vector<string> temp;
            temp.push_back(arr[i][0]);
            for (auto it : st[i])
                temp.push_back(it);
            ans.push_back(temp);
        }
        return ans;
    }
};