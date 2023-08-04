class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        bool done = false;
        int ndx = 0;
        char curr;
        string prefix = "";

        while (!done) {
            if (ndx < strs[0].size()) {
                curr = strs[0][ndx];
                for (int i = 1; i < strs.size(); ++i) {
                    if (curr != strs[i][ndx]) {
                        done = true;
                    }
                }
                if (!done) {
                    prefix += curr;
                }
            } else {
                done = true;
            }
            ndx++;
        }

        return prefix;
    }
};
