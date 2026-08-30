class Solution {
public:
    vector<int> temp;
    int solve(int indx, int prev, vector<int>& nums) {
        if (indx == nums.size())
            return 0;
        int take = 0, notake = 0;
        if (prev == -1 || (nums[indx] % nums[prev] == 0) ||
            (nums[prev] % nums[indx] == 0)) {
            take = 1 + solve(indx + 1, indx, nums);
        }
        notake = solve(indx + 1, prev, nums);
        return max(take, notake);
    }
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<int> dp(arr.size(), 0);
        vector<int> hash(arr.size(), -1);
        vector<int> temp;
        int lastindex = 0;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (((arr[i] % arr[j]) == 0 || (arr[j] % arr[i]) == 0) &&
                    dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
                if (dp[i] > dp[lastindex]) {
                    lastindex = i;
                }
            }
        }
        while (lastindex != -1) {
            temp.push_back(arr[lastindex]);
            lastindex = hash[lastindex];
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};