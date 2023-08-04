#include "valid_palindrome.h"

/* A phrase is a palindrome if, after converting all
 * uppercase letters to lowercase letters and removing
 * all non-alphanumeric characters, it reads the same
 * forward and backward. Alphanumeric characters
 * include letters and numbers. */

class Solution {
public:
    bool isPalindrome(string s) {
        int length = s.size();
        int begin = 0;
        int end = length - 1;

        while (begin < end) {
            while (begin < end && !isalnum(s[begin])) {
                begin++;
            }
            while (begin < end && !isalnum(s[end])) {
                end--;
            }

            if (tolower(s[begin]) != tolower(s[end])) {
                return false;
            }

            begin++;
            end--;
        }

        return true;
    }
};

