class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> q;

        unordered_set<long long> visited;
        q.push(1);

        long long ugly = 1;

        for (int i = 0; i < n; i++) {
            ugly = q.top();
            q.pop();

            if (!visited.count(ugly * 2)) {
                q.push(ugly * 2);
                visited.insert(ugly * 2);
            }
            if (!visited.count(ugly * 3)) {
                q.push(ugly * 3);
                visited.insert(ugly * 3);
            }
            if (!visited.count(ugly * 5)) {
                q.push(ugly * 5);
                visited.insert(ugly * 5);
            }
        }
        return ugly;
    }
};