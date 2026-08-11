class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        unordered_set<int> st;
        int mn = INT_MAX;
        int mx = INT_MIN;

        for (int n : nums) {
            mn = min(mn, n);
            mx = max(mx, n);
            st.insert(n);
        }
        while (mn <= mx) {
            if (!st.count(mn)) {
                ans.push_back(mn);
            }
            mn++;
        }
        return ans;
    }
};