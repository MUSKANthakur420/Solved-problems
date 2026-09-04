class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> st;
        int maxi = 0;
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                int ele = st.top();
                st.pop();
                int pse = (st.empty() ? -1 : st.top());
                int nse = i;
                maxi = max(maxi, arr[ele] * (nse - pse - 1));
            }
            st.push(i);
        }
        int nse = arr.size();
        while (!st.empty()) {
            int ele = st.top();
            st.pop();
            int pse = (st.empty() ? -1 : st.top());
            maxi = max(maxi, arr[ele] * (nse - pse - 1));
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> ans(matrix.size(), 0);
        int maxi = INT_MIN;
        for (int j = 0; j < matrix[0].size(); j++) {
            for (int i = 0; i < matrix.size(); i++) {
                if (matrix[i][j] == '1')
                    ans[i]++;
                else
                    ans[i] = 0;
            }
            maxi = max(maxi, largestRectangleArea(ans));
        }
        return maxi;
    }
};