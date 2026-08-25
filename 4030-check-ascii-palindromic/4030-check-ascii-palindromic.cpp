class Solution {
public:
    bool isPalindromic(string s) {
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            string temp;
            int x = s[i];
            for (int j = 0; j < 8; j++) {
                temp = to_string(x & 1) + temp;
                x >>= 1;
            }
            ans += temp;
        }
        int start = 0, end = ans.size() - 1;
        while (start <= end) {
            if (ans[start] == ans[end]) {
                start++;
                end--;
            } else {
                return false;
            }
        }
        return true;
    }
};