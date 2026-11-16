class Solution {
public:
    bool parseBoolExpr(string s) {
        stack<int> st;
        for (int i = 0; i < s.size();) {
            if (s[i] == ',') {
                i++;
            }
            if (i < s.size() && s[i] != ')') {
                st.push(s[i]);
                i++;
            }
            if (i < s.size() && s[i] == ')') {
                bool t = 0, f = 0;
                while (!st.empty() && st.top() != '(') {
                    if (st.top() == 't')
                        t = 1;
                    if (st.top() == 'f')
                        f = 1;
                    st.pop();
                }
                i++;
                st.pop();
                char op = st.top();
                st.pop();
                if (op == '|') {
                    if (t)
                        st.push('t');
                    else
                        st.push('f');
                }
                if (op == '&') {
                    if (t && !f)
                        st.push('t');
                    else
                        st.push('f');
                }
                if (op == '!') {
                    if (t)
                        st.push('f');
                    else
                        st.push('t');
                }
            }
        }
        return (st.top() == 't') ? true : false;
    }
};