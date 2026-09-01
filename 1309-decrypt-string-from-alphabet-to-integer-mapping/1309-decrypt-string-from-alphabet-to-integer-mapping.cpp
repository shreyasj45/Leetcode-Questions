class Solution {
public:
    string freqAlphabets(string s) {
        string result = "";

        for (int i = 0; i < s.size(); i++) {
            if (i + 2 < s.size() && s[i + 2] == '#') {
                int num = stoi(s.substr(i,2));
                result += char('a' + num - 1);
                i+=2;

            } else {
                int num = stoi(s.substr(i,1));
                result += char('a' + num - 1);
            }
        }
        return result;
    }
};