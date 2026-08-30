class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        unordered_set<int> st;
        for (int num : nums) {
            st.insert(num);
        }

        vector<vector<int>> ans;
        int i = lower;
        while (i <= upper) {
            if (st.count(i)) {
                i++;
                continue;
            }
            int start = i;
            while (i <= upper && !st.count(i)) {
                i++;
            }

            int end = i - 1;
            ans.push_back({start, end});
        }
        return ans;
    }
};