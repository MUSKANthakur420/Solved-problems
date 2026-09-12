class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        int ans = 0;
        for (auto [u, v] : mp) {
            if (v.size() < 3)
                continue;
            int diff = v[1] - v[0];
            bool flag = true;
            for (int j = 2; j < v.size(); j++) {
                if (v[j] - v[j - 1] != diff) {
                    flag = false;
                    break;
                } else
                    flag = true;
            }
            if (flag)
                ans++;
        }
        return ans;
    }
};