class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int count = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                count ++;
            }
            else if(s[i]==')'){
                if(count == 0){
                    s.erase(i,1);
                    i--;
                }
                else{
                    count--;
                }
            }
        }

        int j = s.size()-1;
        while(count!=0){
            if(s[j]=='('){
                s.erase(j,1);
                count--;
                j++;
            }
            j--;
        }
        return s;
    }
};