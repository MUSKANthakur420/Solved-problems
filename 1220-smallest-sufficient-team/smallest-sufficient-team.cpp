class Solution {
public:
    vector<vector<int>> dp, ans;
    int solve(int indx, int mask, int req_mask, vector<int>& formed) {
        if (mask == req_mask) {
            return 0;
        }
        if (indx == formed.size())
            return 10000;
        if (dp[mask][indx] != -1)
            return dp[mask][indx];
        int notake = solve(indx + 1, mask, req_mask, formed);
        int take = 1 + solve(indx + 1, mask | formed[indx], req_mask, formed);
        if (take < notake)
            ans[mask][indx] = 1;
        return dp[mask][indx] = min(take, notake);
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills,
                                       vector<vector<string>>& people) {
        unordered_map<string, int> mp;
        for (int i = 0; i < req_skills.size(); i++) {
            mp[req_skills[i]] = i;
        }
        vector<int> formed;
        for (int i = 0; i < people.size(); i++) {
            int h = 0;
            for (auto it : people[i]) {
                h |= (1 << mp[it]);
            }
            formed.push_back(h);
        }
        int n = req_skills.size();
        dp.assign((1 << 16) - 1, vector<int>(people.size() + 1, -1));
        ans.assign((1 << 16) - 1, vector<int>(people.size() + 1, 0));
        solve(0, 0, (1 << n) - 1, formed);
        vector<int> res;
        int m = 0;
        for (int i = 0; i < people.size(); i++) {
            if (ans[m][i]) {
                res.push_back(i);
                m |= formed[i];
            }
            if (m == (1 << n) - 1)
                break;
        }
        return res;
    }
};