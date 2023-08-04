class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        std::unordered_map<char, int> targetChars;
        std::unordered_map<char, int> windowChars;
        
        // Count the characters in string 't'
        for (char ch : t) {
            targetChars[ch]++;
        }
        
        int left = 0;
        int right = 0;
        int count = 0; // Count of characters in 't' found in the window
        int minWindowSize = INT_MAX;
        int minWindowLeft = 0;
        
        // Iterate over string 's'
        while (right < s.size()) {
            // Expand the window by moving the 'right' pointer
            char ch = s[right];
            windowChars[ch]++;
            
            // Check if the current character is in string 't' and the count matches
            if (targetChars.find(ch) != targetChars.end() && windowChars[ch] <= targetChars[ch]) {
                count++;
            }
            
            // Try to minimize the window by moving the 'left' pointer
            while (count == t.size()) {
                // Update the minimum window size and left index
                int windowSize = right - left + 1;
                if (windowSize < minWindowSize) {
                    minWindowSize = windowSize;
                    minWindowLeft = left;
                }
                
                // Shrink the window by moving the 'left' pointer
                char leftChar = s[left];
                windowChars[leftChar]--;
                
                // Check if the window is still valid after shrinking
                if (targetChars.find(leftChar) != targetChars.end() && windowChars[leftChar] < targetChars[leftChar]) {
                    count--;
                }
                
                left++;
            }
            
            right++;
        }
        
        // Check if a valid window was found
        if (minWindowSize == INT_MAX) {
            return "";
        }
        
        return s.substr(minWindowLeft, minWindowSize);
    }
};
