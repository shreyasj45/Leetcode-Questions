class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long sum = 0;
        long long num = 1;

        for (int x : nums) {
            if (x < num) {
                continue;
            }

            long long gap = x - num;
            long long take = min((long long)k, gap);
            sum += take * (2 * num + take - 1) / 2;
            k -= take;

            if (k == 0) {
                return sum;
            }

            num = x + 1;
        }

        long long take = k;
        sum += take * (2 * num + take - 1) / 2;
        return sum;
    }
};