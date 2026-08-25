class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = k;
        unordered_set<int> st;
        for (int num : nums) {
            st.insert(num);
        }
        while (true) {
            if (st.count(k)) {
                k += n;
            } else {
                return k;
            }
        }
        return -1;
    }
};