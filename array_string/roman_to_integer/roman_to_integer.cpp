#include <string>

class Solution {
private:
    enum RomanNumeral { I, V, X, L, C, D, M };
    const int Int[7] = {1, 5, 10, 50, 100, 500, 1000};
    int find(char x) {
        switch (x) {
            case 'I':
                return I;
            case 'V':
                return V;
            case 'X':
                return X;
            case 'L':
                return L;
            case 'C':
                return C;
            case 'D':
                return D;
            case 'M':
                return M;
            default:
                return -1;
        }
    }
public:
    int romanToInt(std::string s) {
        int finalNum = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i < s.length() - 1 && find(s[i]) < find(s[i + 1])) {
                finalNum -= Int[find(s[i])];
            } else {
                finalNum += Int[find(s[i])];
            }
        }
        return finalNum;
    }
};

