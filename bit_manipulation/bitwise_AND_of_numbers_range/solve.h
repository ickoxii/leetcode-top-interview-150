 /**
  * Given two integers left and right that represent the range [left, right],
  * return the bitwise AND of all numbers in the range, inclusive. */

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;

        // find the common prefix
        while (left < right) {
            left >>= 1;
            right >>= 1;
            ++shift;
        }

        return left << shift;
    }
};
