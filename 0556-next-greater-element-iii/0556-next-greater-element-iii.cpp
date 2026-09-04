class Solution {
public:
    int nextGreaterElement(int x) {
        string s = to_string(x);

        int n = s.size() - 2;
        while (n >= 0 && s[n] >= s[n + 1]) {
            n--;
        }

        if (n < 0) {
            return -1;
        }

        int m = s.size() - 1;
        while (s[m] <= s[n]) {
            m--;
        }

        swap(s[m], s[n]);
        reverse(s.begin() + n + 1, s.end());

        long long ans = stoll(s);
        if (ans > INT_MAX) {
            return -1;
        }
        return ans;
    }
};