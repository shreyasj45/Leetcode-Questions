class Solution {
public:
    struct cmp {
        bool operator()(string a, string b) {
            if (a.size() == b.size()) {
                return a > b;
            }
            return a.size() > b.size();
        }
    };

    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, cmp> q;

        for (string num : nums) {
            q.push(num);
            if (q.size() > k) {
                q.pop();
            }
        }
        return q.top();
    }
};