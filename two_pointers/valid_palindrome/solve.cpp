#include "valid_palindrome.h"

int main() {
    string line;

    // read file
    while (getline(cin, line)) {
        if (isPalindrome(line)) {
            cout << "\"" << line << "\"\npalindrome\n\n";
        }
        else {
            cout << "\"" << line << "\"\nnot a palindrome\n\n";
        }
    }

    return 0;
}
