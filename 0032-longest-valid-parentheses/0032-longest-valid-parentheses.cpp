class Solution {
public:
    int longestValidParentheses(string s) {
        int length = 0;
        int l = 0, r = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                l++;
            } else {
                r++;
            }
            if (l == r) {
                length = max(length, l + r);
            }
            if(r>l){
                r=0,l=0;
            }
        }

        l = 0, r = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(') {
                l++;
            } else {
                r++;
            }
            if (l == r) {
                length = max(length, r + l);
            }
            if(r<l){
                r=0,l=0;
            }
        }
        return length;
    }
};