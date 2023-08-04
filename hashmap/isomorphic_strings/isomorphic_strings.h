/* Given two strings s and t, determine if they are isomorphic.
 *
 * Two strings s and t are isomorphic if the characters in s
 * can be replaced to get t.
 *
 * All occurrences of a character must be replaced with 
 * another character while preserving the order of characters.
 * No two characters may map to the same character, but a 
 * character may map to itself. */

// does not keep track of order of characters

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> s_map, t_map;
        unordered_map<int, int> f_s_map, f_t_map;

        // use hash maps to get frequency of each letter
        for (char c : s) {
            s_map[c]++;
        }

        for (char c : t) {
            t_map[c]++;
        }

        // if they dont have the same number of characters, return
        if (s_map.size() != t_map.size()) {
            return false;
        }

        // use another hash map to get frequency of frequencies
        for (const auto& pair : s_map) {
            f_s_map[pair.second]++;
        }

        for (const auto& pair : t_map) {
            f_t_map[pair.second]++;
        }
        
        /*
        if (f_s_map.size() != f_t_map.size()) {
            return false;
        } */

        // check if frequency of frequencies matches
        for (auto pair : f_s_map) {
            f_t_map[pair.first]--;
            pair.second--;
            if (f_t_map[pair.first] < 0 || pair.second < 0) {
                return false;
            }
        }

        return true;
    }
};
