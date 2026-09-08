// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         long long ans=0;
//         for(int i=0;i<heights.size();i++){
//             int mx = heights[i];
//             for(int right = i+1;right < heights.size();right++){
//                 mx = min(mx,heights[right]);
//                 ans = max(ans, 1LL*mx*(right-i+1));
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans = 0;

        for (int i = 0; i <= heights.size(); i++) {
            int curr = (i == heights.size()) ? 0 : heights[i];

            while (!st.empty() && heights[st.top()] > curr) {
                int h = heights[st.top()];
                st.pop();
                int w;
                if (st.empty()) {
                    w = i;
                } else {
                    w = i - st.top() - 1;
                }
                ans = max(ans, h * w);
            }
            if(i<heights.size()) st.push(i);
        }
        return ans;
    }
};