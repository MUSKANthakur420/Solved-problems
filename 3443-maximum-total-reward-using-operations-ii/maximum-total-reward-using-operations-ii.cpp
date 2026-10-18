class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        constexpr int N = 100000;

        sort(rewardValues.begin(), rewardValues.end());
        rewardValues.erase(unique(rewardValues.begin(), rewardValues.end()),
                           rewardValues.end());
        bitset<N> dp;
        dp[0] = 1;
        for (int x : rewardValues) {
            bitset<N> valid = (dp << (N - x)) >> (N - x);
            dp |= valid << x;
        }
        for (int i = N - 1; i >= 0; i--) {
            if (dp[i])
                return i;
        }
        return 0;
    }
};