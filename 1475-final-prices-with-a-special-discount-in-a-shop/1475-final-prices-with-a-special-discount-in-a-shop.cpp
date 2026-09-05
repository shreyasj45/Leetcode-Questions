class Solution {
public:
    vector<int> finalPrices(vector<int>& nums) {
        stack<int> st;
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                nums[st.top()] -= nums[i];
                st.pop();
            }
            st.push(i);
        }
        return nums;
    }
};