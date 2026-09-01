class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int a = 0;
        for(char ch : s){
            if(ch == 'a'){
                a++;
            }
            else{
                a--;
            }
        }
        return abs(a);
    }
};