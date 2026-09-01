class Solution {
public:
    int minSwaps(string s) {
        int balance = 0;
        int maxNeg = 0;
        for (char ch : s) {
            if (ch == '[') {
                balance++;
            } else {
                balance--;
            }
            maxNeg = max(maxNeg, -balance);
        }
        return (maxNeg + 1) / 2;
    }
};