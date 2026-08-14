class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l = 0, r = 0;
        map<char, int> mp;
        int maxi = INT_MIN;
        while (r < s.size()) {
            mp[s[r]]++;
            if (mp[s[r]] > 2) {
                while (mp[s[r]] > 2) {
                    mp[s[l]]--;
                    l++;
                }
            } else
                maxi = max(maxi, r - l + 1);
            r++;
        }
        return maxi;
    }
};