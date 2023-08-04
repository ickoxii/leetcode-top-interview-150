/* Given a string s, find the length of the longest substring
 * without repeating characters. */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        unordered_set<char> seen;
        int i = 0, j = 0;
        
        while (j < s.size()) {
            // If the current character is not in the set, add it to the set and move the 'j' pointer.
            if (seen.find(s[j]) == seen.end()) {
                seen.insert(s[j++]);
                longest = max(longest, j - i);
            }
            // If the current character is already in the set, remove the character at 'i' from the set and move the 'i' pointer.
            else {
                seen.erase(s[i++]);
            }
        }

        return longest;
    }
};
