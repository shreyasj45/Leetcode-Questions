class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for (auto x : freq) {
            q.push({x.second, -x.first});
        }

        vector<int> ans;
        while (!q.empty()) {
            auto x = q.top();
            for (int i = 0; i < x.first; i++) {
                ans.push_back(-x.second);// (-)because larger number comes first if freqs are same 
            }
            q.pop();
        }

        return ans;
    }
};