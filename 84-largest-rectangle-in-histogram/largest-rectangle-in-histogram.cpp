class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> st;
        int area = INT_MIN;
        for (int i = 0; i < h.size(); i++) {
            while (!st.empty() && h[st.top()] > h[i]) {
                int ele = h[st.top()];
                st.pop();
                int pse = (st.empty()) ? -1 : st.top();
                area = max(area, (i - pse - 1) * ele);
            }
            st.push(i);
        }
        int nse = h.size();
        while (!st.empty()) {
            int ele = h[st.top()];
            st.pop();
            int pse = (st.empty()) ? -1 : st.top();
            area = max(area, (nse - pse - 1) * ele);
        }
        return area;
    }
};