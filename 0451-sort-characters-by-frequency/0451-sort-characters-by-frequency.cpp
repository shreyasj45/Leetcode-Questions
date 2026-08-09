class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (char ch : s) {
            mp[ch]++;
        }

        priority_queue<pair<int, char>> q;
        for (auto it : mp) {
            q.push({it.second, it.first});
        }

        string ans = "";
        while (!q.empty()) {
            auto top = q.top();
            q.pop();
            for (int i = 0; i < top.first; i++) {
                ans += top.second;
            }
        }
        return ans;
    }
};