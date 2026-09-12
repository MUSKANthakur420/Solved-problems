class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int, int> freq;
        for (auto it : nums)
            freq[it]++;
        map<int, vector<int>> mp;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (freq[nums[i]] > 3 || freq[nums[i]] < 3)
                continue;
            mp[nums[i]].push_back(i);
            if (mp[nums[i]].size() == 3) {
                int a = mp[nums[i]][1] - mp[nums[i]][0];
                int b = mp[nums[i]][2] - mp[nums[i]][1];
                if (a == b)
                    cnt++;
            }
        }
        return cnt;
    }
};