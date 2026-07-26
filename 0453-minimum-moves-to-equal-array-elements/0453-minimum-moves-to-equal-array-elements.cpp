class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int i : nums) {
            count += i - nums[0];
        }
        return count;
    }
};