class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minInd = 0;
        int maxInd = 0;
        int mn = INT_MAX;
        int mx = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > mx) {
                maxInd = i;
                mx = nums[i];
            }
            if (nums[i] < mn) {
                minInd = i;
                mn = nums[i];
            }
        }
        int ans = INT_MAX;
        ans = min(ans, max(minInd, maxInd) + 1);
        ans = min(ans, n - min(minInd, maxInd));
        ans = min(ans, min(minInd, maxInd) + 1 + n - max(minInd, maxInd));
        return ans;
    }
};