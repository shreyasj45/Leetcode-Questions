class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mx = nums[nums.size() - 1];
        int count = 0;
        for (int i : nums) {
            count += mx - i;
        }
        return count;
    }
};