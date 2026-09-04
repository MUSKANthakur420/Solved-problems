class Solution {
public:
    bool parseBoolExpr(string exp) {
        stack<char> st;
        for (int i = 0; i < exp.size();) {
            if (exp[i] == ',') {
                i++;
                // continue;
            }
            if (exp[i] != ')') {
                st.push(exp[i]);
                i++;
                // continue;
            } else {
                bool final = false;
                string form = "";
                while (!st.empty() && st.top() != '(') {
                    form += st.top();
                    st.pop();
                }
                st.pop();
                char op = st.top();
                st.pop();
                if (op == '&') {
                    final = true;
                    for (auto it : form) {
                        final = final & (it == 'f' ? false : true);
                    }
                } else if (op == '|') {
                    for (auto it : form) {
                        final = final | (it == 'f' ? false : true);
                    }
                } else {
                    for (auto it : form) {
                        final = !(it == 'f' ? false : true);
                    }
                }
                st.push(final ? 't' : 'f');
                i++;
            }
        }
        return st.top() == 't';
    }
};