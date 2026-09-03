class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        int minEven = INT_MAX;

        for (int i : nums1) {
            if (i % 2 == 0) {
                minEven = min(minEven, i);
            } else {
                minOdd = min(minOdd, i);
            }
        }

        bool even = true;
        for (int x : nums1) {
            if (x % 2 != 0) {
                if (minOdd >= x) {
                    even = false;
                }
            }
        }
        if (even)
            return true;

        bool odd = true;
        for (int x : nums1) {
            if (x % 2 == 0) {
                if (minOdd >= x) {
                    odd = false;
                }
            }
        }
        if (odd)
            return true;
        return false;
    }
};