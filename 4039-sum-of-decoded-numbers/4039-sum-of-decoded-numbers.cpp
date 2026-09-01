class Solution {
public:
    int sumDecoded(vector<long long>& nums) {
        long long ans = 0;

        for (long long num : nums) {
            int w = num % 10;
            long long d = num / 10;

            string s = to_string(d);

            long long x = stoll(s.substr(0, w));
            long long y = stoll(s.substr(w));

            long long val = 1;

            while (y > 0) {
                if (y % 2 == 1)
                    val = (val * x) % 1000000007;

                x = (x * x) % 1000000007;
                y /= 2;
            }
            ans = (ans + val) % 1000000007;
        }
        return ans;
    }
};