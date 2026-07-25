class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int count = 0;
        for(int j = num1; j <= num2; j++){
            string s = to_string(j);
            for(int i = 1; i<s.size()-1; i++){
                if((s[i]-'0' > s[i-1]-'0' && s[i]-'0' > s[i+1]-'0') || (s[i]-'0' < s[i-1]-'0' && s[i]-'0' < s[i+1]-'0')){
                    count++;
                }
            }
        }
        return count;
    }
};