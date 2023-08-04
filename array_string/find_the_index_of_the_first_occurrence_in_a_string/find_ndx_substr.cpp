class Solution {
public:
    int strStr(string haystack, string needle) {
        int ndx = 0;
        int h_size = haystack.size(), n_size = needle.size();
        bool found = false;

        while (not found) {
            // break if remaining letters in haystack is less than
            // in needle
            if (h_size - ndx < n_size) {
                return -1;
            }

            if (needle[ndx] == haystack[ndx]) {
                int skip = 0;
                for (int i = 0; i < needle.size(); ++i) {
                    if (needle[i] != haystack[i]) {
                        skip = i;
                    }
                }
                if (skip == 0) {
                    found = true;
                } else {
                    ndx += skip;
                }
            }
        }

        return ndx;
    }
};
