class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> ans;
        for (int x : nums) {
            int bit = 0;
            string s = "";

            int power = pow(2, 25);
            int z = x / power;
            x = x % power;

            while (x) {
                if (x % 2 == 1) {
                    s += char('a' + bit);
                }
                x /= 2;
                bit++;
            }
            reverse(s.begin(), s.end());
            s = string(z,'z') + s;
            ans.push_back(s);
        }
        return ans;
    }
};