/* Given a pattern and a string s, find if s follows
 * the same pattern.
 *
 * Here, 'follows' means a full match, such that
 * there is a bijection between a letter in pattern
 * an d anon-empty word in s. */

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> pMap;
        unordered_map<string, char> sMap;
        string word;
        istringstream inSS;
        inSS.str(s);
        int ndx = 0;
        
        while (getline(inSS, word, ' ')) {
            // check if index out of bounds
            if (ndx >= pattern.size()) {
                return false;
            }
            
            char p = pattern[ndx];

            // check if mapped to something else
            if ((pMap.count(p) && pMap[p] != word) ||
                (sMap.count(word) && sMap[word] != p)) {
                return false;
            }

            // if not mapped, map the word to a pattern
            if (!pMap.count(p) && !sMap.count(word)) {
                pMap[p] = word;
                sMap[word] = p;
            } else {
                // if already mapped, check if mapped in order
                if (pMap[p] != word || sMap[word] != p) {
                    return false;
                }
            }
            
            ++ndx;
        }

        if (ndx < pattern.size()) {
            return false;
        }

        return true;
    }
};
