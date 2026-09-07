class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int e = 0, o = 0;
        for (auto it : nums) {
            if (it % 2 == 0)
                e++;
            else
                o++;
        }
        bool even = false, odd = false;
        int maxlen = 0;
        int ev = 0, od = 0;
        for (auto it : nums) {
            if (it % 2 == 0 && !even) {
                ev++;
                even = true;
            } else if (it % 2 == 1 && even) {
                od++;
                even = false;
            }
            maxlen = max(maxlen, ev + od);
        }
        ev = 0, od = 0;
        for (auto it : nums) {
            if (it % 2 == 1 && !odd) {
                ev++;
                odd = true;
            } else if (it % 2 == 0 && odd) {
                od++;
                odd = false;
            }
            maxlen = max(maxlen, ev + od);
        }
        return max({maxlen, e, o});
    }
};