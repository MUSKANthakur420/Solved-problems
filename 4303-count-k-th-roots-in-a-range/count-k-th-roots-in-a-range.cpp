
class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        int cnt = 0;
        int c = 0;
        if (k == 1) {
            return r - l + 1;
        }
        for (int i = 1; i < r; i++) {
            double ans = pow(i, k);
            if (ans <= r)
                cnt++;
            else
                break;
            if (ans < l)
                c++;
        }
        if (l == 0)
            return abs(cnt - c) + 1;
        return abs(cnt - c);
    }
};