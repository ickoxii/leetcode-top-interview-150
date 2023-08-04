class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;
        vector<vector<string>> anagrams;

        if (strs.empty()) {
            vector<string> empty;
            empty.push_back("");
            anagrams.push_back(empty);
            return anagrams;
        }

        for (const string& word : strs) {
            // sort the letters in word
            string sortedChars = word;
            sort(sortedChars.begin(), sortedChars.end());

            anagramGroups[sortedChars].push_back(word);
        }

        for (const pair<string, vector<string>> entry : anagramGroups) {
            anagrams.push_back(entry.second);
        }

        return anagrams;
    }
};
