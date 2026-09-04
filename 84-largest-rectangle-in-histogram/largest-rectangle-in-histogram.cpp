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
};