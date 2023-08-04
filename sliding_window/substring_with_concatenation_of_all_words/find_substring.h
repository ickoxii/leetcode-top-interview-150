/* You are given a string s and an array of string words.
 * All the strings of words are of the same length.
 *
 * A concatenated substring in s is a substring that 
 * contains all the strings of any permutation of words
 * concatenated.
 *
 * For example, if words = ["ab","cd","ef"], then "abcdef",
 * "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are
 * all concatenated strings. "acdbef" is not a concatenated 
 * substring because it is not in the concatenation of any
 * permutation of words.
 *
 * Return the starting indices of all the concatenated
 * substrings in s. You can return the answer in any order. */

/* ex 1: s = "barfoothefoobarman", words = ["foo","bar"]
 * output: [0,9]
 * "barfoo" and "foobar" are the two concatenations of words
 * that appear in s. these appear at indices 0 and 9 */

// uses the sliding window technique

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> combinationIndices;
        int strLength = s.length();
        int wordsCount = words.size();
        int totalWordsLength = 0;

        // Calculate the total length of all target words combined
        for (const std::string& word : words) {
            totalWordsLength += word.length();
        }

        // Base case: If the string length is less than the total length of all target words combined,
        // there can't be any valid combinations
        if (strLength < totalWordsLength) {
            return combinationIndices;
        }

        std::unordered_map<std::string, int> wordCounts;

        // Store the counts of each word in the unordered map
        for (const std::string& word : words) {
            wordCounts[word]++;
        }

        int wordLength = words[0].length();

        for (int i = 0; i < wordLength; i++) {
            int left = i;
            int count = 0;
            std::unordered_map<std::string, int> windowWordsCount;

            for (int right = i; right <= strLength - wordLength; right += wordLength) {
                std::string currentWord = s.substr(right, wordLength);

                // If the current word is not part of the target words or its count exceeds the occurrence in the target words,
                // move the left pointer to the next position and adjust the counts
                if (wordCounts.find(currentWord) == wordCounts.end()) {
                    left = right + wordLength;
                    count = 0;
                    windowWordsCount.clear();
                } else {
                    windowWordsCount[currentWord]++;
                    count++;

                    // If the count of the current word exceeds the occurrence in the target words,
                    // move the left pointer until the counts are balanced
                    while (windowWordsCount[currentWord] > wordCounts[currentWord]) {
                        std::string leftWord = s.substr(left, wordLength);
                        windowWordsCount[leftWord]--;
                        count--;
                        left += wordLength;
                    }

                    // If all target words are found in the substring, add the starting index to the combinationIndices vector
                    if (count == wordsCount) {
                        combinationIndices.push_back(left);
                        std::string leftWord = s.substr(left, wordLength);
                        windowWordsCount[leftWord]--;
                        count--;
                        left += wordLength;
                    }
                }
            }
        }

        return combinationIndices;
    }
};
