/* Given two strings ransomNote and magazine, return
 * true if ransomNote can be constructed by using
 * the letters from magazine and false otherwise.
 *
 * Each letter in magazine can only be used once
 * in ransomNote. */

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> letters;

        // load up the scrapbook 
        for (char c : magazine) {
            letters[c]++;
        }

        for (char c : ransomNote) {
            if (letters.count(c) == 0) {
                return false;
            } else {
                letters[c]--;
                if (letters[c] == 0) {
                    letters.erase(c);
                }
            }
        }

        return true;
    }
};
