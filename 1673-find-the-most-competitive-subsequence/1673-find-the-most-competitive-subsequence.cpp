class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> st;
        int remove = nums.size() - k;

        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && remove && st.back() > nums[i]) {
                st.pop_back();
                remove--;
            }
            st.push_back(nums[i]);
        }

        while (remove--) {
            st.pop_back();
        }
        return st;
    }
};