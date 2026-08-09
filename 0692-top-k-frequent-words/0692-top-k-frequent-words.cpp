class Solution {
public:
    struct cmp {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        }
    };

    vector<string>topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;

        for (string word : words) {
            mp[word]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp > q;

        for (auto& it : mp) {
            q.push({it.second, it.first});

            if (q.size() > k) {
                q.pop();
            }
        }

        vector<string> ans;

        while (!q.empty()) {
            ans.push_back(q.top().second);
            q.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};