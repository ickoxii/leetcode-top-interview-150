#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, char> s_map, t_map;

        for (int i = 0; i < s.length(); i++) {
            char s_char = s[i];
            char t_char = t[i];

            // Check if the characters are already mapped differently
            if ((s_map.count(s_char) && s_map[s_char] != t_char) ||
                (t_map.count(t_char) && t_map[t_char] != s_char)) {
                return false;
            }

            // If not mapped, create the mapping
            if (!s_map.count(s_char) && !t_map.count(t_char)) {
                s_map[s_char] = t_char;
                t_map[t_char] = s_char;
            } else {
                // Check if the characters are mapped correctly in terms of order
                if (s_map[s_char] != t_char || t_map[t_char] != s_char) {
                    return false;
                }
            }
        }

        return true;
    }
};
