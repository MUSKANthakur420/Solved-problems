class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int> mp;
        for (auto it : s)
            mp[it]++;
        string forward = "";
        string middle = "";
        for (auto it : mp) {
            if (it.second >= 2 && it.second % 2 == 0) {
                int times = it.second / 2;
                while (times != 0) {
                    forward += it.first;
                    times--;
                }
                mp[it.first] = 0;
            }
            if (it.second >= 2 && it.second % 2 == 1) {
                int times = (it.second - 1) / 2;
                while (times != 0) {
                    forward += it.first;
                    times--;
                }
                mp[it.first] = 1;

            } else if (it.second == 1) {
                mp[it.first] = 0;
                middle += it.first;
            }
        }
        for (auto it : mp) {
            if (it.second == 1)
                middle += it.first;
        }
        string back = forward;
        reverse(back.begin(), back.end());
        return forward + middle + back;
    }
};