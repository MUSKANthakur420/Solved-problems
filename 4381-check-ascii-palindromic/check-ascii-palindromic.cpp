class Solution {
public:
    bool isPalindromic(string s) {
        map<char, int> mp;
        int k = 97;
        for (char i = 'a'; i <= 'z'; i++) {
            mp[i] = k;
            k++;
        }
        string res = "";
        for (auto it : s) {
            res += bitset<8>(mp[it]).to_string();
        }
        string rev = res;
        reverse(rev.begin(), rev.end());
        return rev == res;
    }
};