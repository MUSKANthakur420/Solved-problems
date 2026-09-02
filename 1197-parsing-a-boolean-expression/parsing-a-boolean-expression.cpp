class Solution {
public:
    bool parseBoolExpr(string s) {
        stack<char> st;
        for (int i = 0; i < s.size();) {
            if (s[i] == ',') {
                i++;
            } else if (s[i] != ')') {
                st.push(s[i]);
                i++;
            } else {
                string res = "";
                while (!st.empty() && st.top() != '(') {
                    res.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op = st.top();
                st.pop();
                bool ans;
                if (op == '&') {
                    ans = true;

                    for (auto it : res) {
                        ans = ans && (it == 't');
                    }
                }

                else if (op == '|') {
                    ans = false;

                    for (auto it : res) {
                        ans = ans || (it == 't');
                    }
                }

                else {
                    ans = !(res[0] == 't');
                }
                st.push(ans == 1 ? 't' : 'f');
                i++;
            }
        }
        return st.top() == 't';
    }
};