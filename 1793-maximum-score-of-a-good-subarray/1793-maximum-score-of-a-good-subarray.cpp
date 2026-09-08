class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int left = k;
        int right = k;
        int mn = nums[k];
        int ans = mn;
        while (left > 0 || right < nums.size() - 1) {
            if (left == 0) {
                right++;
            } else if (right == nums.size() - 1) {
                left--;
            } else if (nums[left - 1] >= nums[right + 1]) {
                left--;
            } else {
                right++;
            }
            mn = min(mn, min(nums[left], nums[right]));
            int l = right - left + 1;
            ans = max(ans, l * mn);
        }
        return ans;
    }
};