/* Given two strings s and t of lengths m and n respectively,
 * return the minimum window substring of s such that every
 * character in t (including duplicates) is included in the
 * window. If there is not such substring, return the empty
 * string "".
 *
 * Test cases are such that the answer is unique. */

// use sliding window

class Solution {
public:
    string minWindow(string s, string t) {
        int s_size = s.size();
        int t_size = t.size();
        int windowLeft = 0, windowRight = 0;
        int currWindowSize = 0;
        int minWindowSize = INT_MIN;
        int start = 0;
        string substr = "";
        unordered_map<char, int> letters, seen;

        // early return, s has less characters than t
        if (s_size < t_size) {
            return substr;
        }

        // get all letters in t
        for (int i = 0; i < t_size; ++i) {
            if (letters.find(t[i]) == letters.end()) {
                letters.insert(t[i], 0);
            } else {
                letters[t[i]]++;
            }
        }

        // now we go through s
        while (windowRight < s_size) { 
            if (seen.size() <= t_size) {
                if (letters.find(s[windowRight]) != letters.end()) {
                    unordered_map<char, int>::iterator iter;
                    iter = seen.find(s[windowRight]);
                    if (iter != seen.end()) {
                        (*iter)++;
                    } else {
                        seen.insert(s[windowRight]);
                    }
                }
                ++windowRight;
            } else {
                if (windowRight - windowLeft + 1 < minWindowSize) {
                    minWindowSize = windowRight - windowLeft + 1;
                    start = windowLeft;
                }
                minWindowSize = min(minWindowSize, windowRight - windowLeft + 1); 
                // check left
                ++windowLeft;
                if (letters.find(s[windowLeft]) == letters.end()) {
                    // do nothing, keep going
                } else {
                    // lower the count
                    unordered_map<char, int>::iterator iter;
                    iter = seen.find(s[windowLeft]);
                    if (*iter > 0) {
                        (*iter)--;
                    }
                }
            }
        }

        // add characters to answer
        for (int i = 0; i < minWindowSize; ++i) {
            substr += s[start+i];
        }

        return substr;
    }
};
