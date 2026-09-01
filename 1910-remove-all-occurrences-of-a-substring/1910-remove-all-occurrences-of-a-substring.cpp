class Solution {
public:
    string removeOccurrences(string s, string part) {
        string result = "";
        for (int i = 0; i < s.size(); i++) {
            result += s[i];
            if (result.size() >= part.size()) {
                string sub = result.substr(result.size() - part.size(), part.size());
                if (sub == part) {
                    result.erase(result.size() - part.size(), part.size());
                }
            }
        }
        return result;
    }
};