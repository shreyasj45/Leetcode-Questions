class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        while (n) {
            int count = 0;
            for (int i = 0; i < citations.size(); i++) {
                if (citations[i] >= n) {
                    count++;
                }
            }
            if (n <= count) {
                return n;
            }
            n--;
        }
        return 0;
    }
};