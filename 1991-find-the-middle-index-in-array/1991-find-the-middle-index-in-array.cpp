class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum2 = 0;
        for (int x : nums) {
            sum2 += x;
        }

        int sum1 = 0;
        for (int x = 0; x < nums.size(); x++) {
            sum2 -= nums[x];
            if (sum1 == sum2) {
                return x;
            }
            sum1 += nums[x];
        }
        return -1;
    }
};