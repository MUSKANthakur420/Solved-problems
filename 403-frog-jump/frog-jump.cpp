class Solution {
public:
    unordered_map<int, unordered_map<int, int>> mp;
    bool solve(int indx, int jump, vector<int>& arr) {
        if (indx == arr.size() - 1) {
            return 1;
        }
        if (mp.count(indx) && mp[indx].count(jump))
            return mp[indx][jump];
        int take1 = 0, take2 = 0, take3 = 0;
        for (int i = indx + 1; i < arr.size(); i++) {
            int diff = arr[i] - arr[indx];
            int j1 = jump + 1;
            int j2 = jump - 1;
            if (diff == j1) {
                take1 = solve(i, j1, arr);
            }
            if (diff == j2)
                take2 = solve(i, j2, arr);
            if (diff == jump)
                take3 = solve(i, jump, arr);
        }
        return mp[indx][jump] = take1 || take2 || take3;
    }
    bool canCross(vector<int>& arr) {
        int ans = solve(0, 0, arr);
        return ans;
    }
};