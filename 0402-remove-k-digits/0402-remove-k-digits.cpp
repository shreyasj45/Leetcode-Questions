class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        for (char ch : num) {
            while (!st.empty() && k != 0 && st.back() > ch) {
                st.pop_back();
                k--;
            }
            st.push_back(ch);
        }

        while (k--) {
            st.pop_back();
        }

        while (st[0] == '0') {
            st.erase(0, 1);
        }

        if (st == "") {
            return "0";
        }
        return st;
    }
};