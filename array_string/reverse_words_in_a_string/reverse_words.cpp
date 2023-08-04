class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string answer = "";
        char *delim = " ";
        
        // turn into c_string
        char *ptr = strdup(s.c_str());
        
        // tokenize and add each word to list
        ptr = strtok(ptr, delim);
        while (ptr != NULL) {
            words.push_back(ptr);
            ptr = strtok(NULL, delim);
        }

        // reverse list
        for (int i = words.size() - 1; i >= 0; --i) {
            answer += words[i];
            if (i != 0) {
                answer += delim;
            }
        }

        // the ptr returned by strdup must be deallocated
        // using free or else a memory leak will occur
        free(ptr);

        return answer;
    }
};
