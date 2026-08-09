class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int> st;
        for (int num : nums) {
            st.insert(num);
        }
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto it : st) {
            q.push(it);
            if (q.size() > 3) {
                q.pop();
            }
        }

        if (q.size() < 3) return *max_element(nums.begin(), nums.end());

        return q.top();
    }
};