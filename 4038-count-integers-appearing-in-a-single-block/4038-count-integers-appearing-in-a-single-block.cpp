class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, int> mp;
        unordered_set<int> st;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];

            if (mp.count(x) && i != mp[x] + 1) {
                st.insert(x);
            }
            mp[x] = i;
        }
        return mp.size() - st.size();
    }
};