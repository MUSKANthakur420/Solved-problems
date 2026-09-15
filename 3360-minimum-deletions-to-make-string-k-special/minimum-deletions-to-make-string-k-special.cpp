class Solution {
public:
    int minimumDeletions(string word, int k) {
        map<int, int> mp;
        int maxi = 0;
        for (auto it : word) {
            mp[it - 'a']++;
            maxi = max(maxi, mp[it - 'a']);
        }
        int mincost = INT_MAX;
        for (int i = 0; i <= maxi; i++) {
            int cost = 0;
            for (auto it : mp) {
                int f = it.second;
                if (f < i)
                    cost += f;
                else if (f > i + k)
                    cost += f - (i + k);
            }
            mincost = min(mincost, cost);
        }
        return mincost;
    }
};