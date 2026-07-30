class Solution {
public:
    int minimumPushes(string word) {
        if (word.size() <= 8)
            return word.size();
        int sum = 0;
        for (int i = 0; i < word.size(); i++) {
            if (i >= 0 && i <= 7)
                sum += 1;
            else if (i >= 8 && i <= 15)
                sum += 2;
            else if (i >= 16 && i <= 23)
                sum += 3;
            else
                sum += 4;
        }
        return sum;
    }
};