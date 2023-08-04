#ifndef VALID_ANAGRAM_H
#define VALID_ANAGRAM_H
/*  Given two strings s and t, return true if t is an anagram of s, 
    and false otherwise.
    
    An anagram is a word or phrase formed by rearranging the letters
    of a different word of phrase, typically using all the original
    letters exactly once. */

// works first try baby

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /* isAnagram
    
    This function counts the number of characters in each of the two
    strings. If the two strings share the same characters, and each 
    character share the same frequency, then the two words are anagrams
    of each other.
    
    input:  s - string 1
            t - string 2
            
    return:
    true if s and t are anagrams, false if not. */
    bool isAnagram(string s, string t);
};

bool Solution::isAnagram(string s, string t)
{
    // if they do not have the same number of characters,
    // they cannot be an anagram
    if (s.size() != t.size())
    {
        return false;
    }

    unordered_map<char, int> s_map, t_map;

    // get frequency for each letter
    for (int i = 0; i < s.size(); ++i)
    {
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