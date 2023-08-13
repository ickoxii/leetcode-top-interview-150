 /**
  * reverse the bits of a given 32 bit unsigned integer. */

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;

        for (int i = 0; i < 32; ++i) {
            result <<= 1;       // shift the result left by one position
            if (n & 1) {        // check if last bit of n is set
                result |= 1;    // if set, then set last bit of result
            }
            n >>= 1;            // shift n right by one position to check next bit
        }

        return result;
    }
};
