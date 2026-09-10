class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto x : tokens) {
            if (x == "+" || x == "-" || x == "*" || x == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                int result;
                if (x == "+") {
                    result = a + b;
                } else if (x == "-") {
                    result = a - b;
                } else if (x == "*") {
                    result = a * b;
                } else if (x == "/") {
                    result = a / b;
                }
                st.push(result);
            } else {
                st.push(stoi(x));
            }
        }
        return st.top();
    }
};