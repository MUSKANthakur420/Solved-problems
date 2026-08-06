class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;
        int val = 0, prev = 2, prev2 = 1;
        for (int i = 3; i <= n; i++) {
            val = prev + prev2;
            prev2 = prev;
            prev = val;
        }
        return val;
    }
};