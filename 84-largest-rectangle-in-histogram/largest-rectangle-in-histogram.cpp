class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> st;
        int area = INT_MIN;
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                int ele = st.top();
                st.pop();
                int nse = i;
                int pse = (st.empty() ? -1 : st.top());
                area = max(area, arr[ele] * (nse - pse - 1));
            }
            st.push(i);
        }
        int nse = arr.size();
        while (!st.empty()) {
            int ele = st.top();
            st.pop();
            int pse = (st.empty() ? -1 : st.top());
            area = max(area, arr[ele] * (nse - pse - 1));
        }
        return area;
    }
};