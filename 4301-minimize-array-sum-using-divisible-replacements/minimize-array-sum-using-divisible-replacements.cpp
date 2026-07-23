class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        long long sum = 0;
        map<int, int> mp;
        for (auto it : nums)
            mp[it]++;
        for (auto it : nums) {
            int mini = it;
            for (int j = 1; j * j <= it; j++) {

                if (it % j == 0) {
                    if (mp.find(j) != mp.end())
                        mini = min(mini, j);
                    if (j != (it / j) && mp.find(it / j) != mp.end())
                        mini = min(mini, it / j);
                }
            }
            sum += mini;
        }
        return sum;
    }
};