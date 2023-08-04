class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> lines;
        vector<int> wpl; // words per line
        int numLines = 0;
        string *last = NULL;

        // add the first word
        lines.push_back(words[0]);
        wpl.push_back(1);
        last = &lines[0];
        for (int i = 1; i < words.size(); ++i) {
            // if the word can fit on the line, add it
            if (lines[numLines].size() + words[i].size() < maxWidth - 1) {
                lines[numLines] += " ";
                lines[numLines] += words[i];
                wpl[numLines]++;
            } 
            else { // otherwise add it to a new line
                lines.push_back(words[i]);
                wpl.push_back(1);
                numLines++;
            }
        }

        // tokenize each line
        // find number of words
        for (int i = 0; i < lines.size(); ++i) {
            if (wpl[i] == 1 || i == lines.size() - 1) {
                while (lines[i].size() < maxWidth) {
                    lines[i] += " ";
                }
            } else {
                int num_char = lines[i].size() - (wpl[i] - 1);
                int num_spaces = maxWidth - num_char;
                string new_line = "";
                int spaces_per = num_spaces / (wpl[i] - 1);
                char *ptr = strdup(lines[i].c_str());
                int spaces_left = num_spaces % (wpl[i] - 1);

                ptr = strtok(ptr, " ");
                for (int j = 0; j < wpl[i]-1; ++j) {
                    
                    new_line += ptr;
                    if (j != wpl[i] - 1) {
                        for (int k = 0; k < spaces_per; ++k) {
                            new_line += " ";
                        }
                    }
                    if (spaces_left > 0) {
                        new_line += " ";
                        spaces_left--;
                    }
                    ptr = strtok(NULL, " ");
                }
                if (ptr) {
                    new_line += ptr;
                }

                lines[i] = new_line;

                //free(ptr);
            }
        }

        return lines;
    }
};
