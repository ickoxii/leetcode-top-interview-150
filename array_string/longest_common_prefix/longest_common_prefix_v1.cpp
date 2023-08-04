/*
runtime: 0 ms (how the fuck??)
beats 100%

memory: 9.2 mb
beats 38.36%
*/

#include <vector>
#include <string>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }

        string prefix_leader = "";

        // Find length of shortest word
        int shortest_word = strs[0].length();
        for (const auto& str : strs) {
            shortest_word = min(shortest_word, static_cast<int>(str.length()));
        }

        // Loop through characters
        for (int i = 0; i < shortest_word; i++) {
            char current_char = strs[0][i];

            // Check if all words contain the same letter
            for (const auto& str : strs) {
                if (str[i] != current_char) {
                    return prefix_leader;
                }
            }

            // Update prefix_leader
            prefix_leader += current_char;
        }

        return prefix_leader;
    }
};

