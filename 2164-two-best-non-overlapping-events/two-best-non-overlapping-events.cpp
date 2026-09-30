
class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), comp);

        int n = events.size();

        vector<int> suffix(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = max(suffix[i + 1], events[i][2]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {

            int l = i + 1;
            int r = n - 1;
            int pos = n;

            while (l <= r) {
                int mid = l + (r - l) / 2;

                if (events[mid][0] > events[i][1]) {
                    pos = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            int take = events[i][2];

            if (pos < n) {
                take += suffix[pos];
            }

            ans = max(ans, take);
        }

        return ans;
    }
};