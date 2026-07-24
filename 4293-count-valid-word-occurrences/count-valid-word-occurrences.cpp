class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks,
                                     vector<string>& queries) {
        string final = "";
        map<string, int> mp;
        for (auto it : chunks) {
            final += it;
        }
        string curr = "";
        for (int i = 0; i < final.size(); i++) {
            if (final[i] >= 'a' && final[i] <= 'z') {
                curr += final[i];
            } else if (final[i] == '-') {
                if ((i - 1) >= 0 && (i + 1) < final.size() &&
                    final[i - 1] >= 'a' && final[i - 1] <= 'z' &&
                    final[i + 1] >= 'a' && final[i + 1] <= 'z') {
                    curr += '-';
                } else {
                    if (!curr.empty())
                        mp[curr]++;
                    curr = "";
                }
            } else {
                if (!curr.empty())
                    mp[curr]++;
                curr = "";
            }
        }
        if (!curr.empty())
            mp[curr]++;
        vector<int> ans;
        for (auto it : queries) {
            ans.push_back(mp[it]);
        }
        return ans;
    }
};