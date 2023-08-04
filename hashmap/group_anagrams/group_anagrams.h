#ifndef GROUP_ANAGRAMS_H
#define GROUP_ANAGRAMS_H

/* Given an array of strings strs, group the anagrams together.
 * You can return the answer in any order. */

// too slow

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs);
private:
    bool isAnagram(string s, string t);
};

vector<vector<string>> Solution::groupAnagrams(vector<string>& strs) {
    vector<vector<string>> anagrams;

    for (string word : strs) {
        bool foundGroup = false;
        for ((vector<vector<string>>::iterator iter = anagrams.begin());
             (iter != anagrams.end()) || foundGroup;
             (++iter)) {
            if (isAnagram((*iter)[0], word)) {
                (*iter).push_back(word);
                foundGroup = true;
            }
        }
        if (!foundGroup) {
            vector<string> newGroup;
            newGroup.push_back(word);
            anagrams.push_back(newGroup);
        }
    }

    return anagrams;
}

bool Solution::isAnagram(string s, string t) {
    // if they do not have the same number of characters,
    // they cannot be an anagram
    if (s.size() != t.size()){
        return false;
    }

    unordered_map<char, int> s_map, t_map;

    // get frequency for each letter
    for (int i = 0; i < s.size(); ++i){
        char s_char = s[i];
        char t_char = t[i];

        // update frequency
        s_map[s_char]++;
        t_map[t_char]++;
    }

    // if they dont have the same number of unique characters,
    // they cannot be an anagram
    if (s_map.size() != t_map.size()) {
        return false;
    }

    /* for each character in s, check if it also exists in t,
    and if it does, check that the frequencies match */
    // auto = std::pair
    for (const pair<char, int>& s_char : s_map) {
        if (!t_map.count(s_char.first)) {
            return false;
        }
        if (t_map[s_char.first] != s_char.second) {
            return false;
        }
    }

    return true;
}

#endif
