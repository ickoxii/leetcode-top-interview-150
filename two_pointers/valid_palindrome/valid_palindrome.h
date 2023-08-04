#ifndef IS_PALINDROME_H
#define IS_PALINDROME_H
#include <iostream>
#include <string>
using namespace std;

/* A phrase is a palindrome if, after converting all
 * uppercase letters to lowercase letters and removing
 * all non-alphanumeric characters, it reads the same
 * forward and backward. Alphanumeric characters
 * include letters and numbers. */

class Solution {
public:
    bool isPalindrome(string s);
};

#endif
