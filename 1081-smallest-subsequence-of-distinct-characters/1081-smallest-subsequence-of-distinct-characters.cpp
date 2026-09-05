class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char, int> freq;
        unordered_map<char, bool> used;

        for (char ch : s) {
            freq[ch]++;
        }

        string ans = "";
        for (char ch : s) {
            freq[ch]--;
            if (used[ch]) {
                continue;
            }
            while (!ans.empty() && ans.back() > ch && freq[ans.back()] > 0) {
                used[ans.back()] = false;
                ans.pop_back();
            }

            ans += ch;
            used[ch] = true;
        }
        return ans;
    }
};