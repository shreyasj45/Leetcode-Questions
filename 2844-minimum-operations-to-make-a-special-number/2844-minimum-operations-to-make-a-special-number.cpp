class Solution {
public:
    int minimumOperations(string num) {
        int ans = num.size();
        vector<string> target = {"00","25","50","75"};
        for (int i = 0; i < num.size(); i++) {
            if (num[i] == '0') {
                ans = min(ans, (int)num.size() - 1);
                break;
            }
        }

        for(string t :target){
            int j=1;
            int count =0;
            for(int i = num.size()-1;i>=0;i--){
                if(num[i]==t[j]){
                    j--;
                    if(j<0){
                        ans = min(ans,count);
                        break;
                    }
                }
                else{
                    count++;
                }
            }
        }
        return ans;
    }
};