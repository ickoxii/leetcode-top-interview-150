class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ndx = 0;

        for (int i = 0; i < t.size(); ++i) {
            if (t[i] == s[ndx]) {
                ndx++;
            }
        }

        if (ndx < s.size()) {
            return false;
        }

        return true;
    }
};
