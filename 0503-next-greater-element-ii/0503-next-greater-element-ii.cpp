class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        stack<int> st;

        for (int i = 0; i < 2 * nums.size() - 1; i++) {
            int x = nums[i % nums.size()];
            while (!st.empty() && nums[st.top()] < x) {
                ans[st.top()] = x;
                st.pop();
            }
            if (i < nums.size()) {
                st.push(i);
            }
        }
        return ans;
    }
};