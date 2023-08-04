class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, char> s_map, t_map;
        char s_char, t_char;

        for (int i = 0; i < s.size(); ++i) {
            s_char = s[i];
            t_char = t[i];

            // are these characters mapped to something else?
            if ((s_map.count(s_char) && s_map[s_char] != t_char) || 
                (t_map.count(t_char) && t_map[t_char] != s_char)) {
                return false;
            }

            // if not mapped, map the characters together
            if (!s_map.count(s_char) && !t_map.count(t_char)) {
                // map the characters
                s_map[s_char] = t_char;
                t_map[t_char] = s_char;
            } else {
                // if already mapped, check if mapped in order
                if (s_map[s_char] != t_char || t_map[t_char] != s_char) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
