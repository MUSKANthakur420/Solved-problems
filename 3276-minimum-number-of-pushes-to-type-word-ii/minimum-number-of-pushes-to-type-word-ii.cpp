class Solution {
public:
    int minimumPushes(string word) {
        map<char, int> mp;
        for (auto it : word)
            mp[it]++;
        int cnt = 0;
        int sum = 0;
        vector<int> freq;
        for (auto it : mp)
            freq.push_back(it.second);
        sort(freq.begin(), freq.end(), greater<int>());
        for (auto it : freq) {
            if (cnt >= 0 && cnt <= 7) {
                sum += it;
            } else if (cnt >= 8 && cnt <= 15) {
                sum += it * 2;
            } else if (cnt >= 16 && cnt <= 23)
                sum += it * 3;
            else
                sum += it * 4;
            cnt++;
        }
        return sum;
    }
};