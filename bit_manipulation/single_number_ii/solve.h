 /**
  * Given an integer array nums where every element appears three times
  * except for one, which appears exactly once. Find the single element
  * and return it.
  *
  * You must implement a solution with a linear runtime complexity and
  * use only constant extra space. */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0, threes = 0;

        for (int i = 0; i < nums.size(); ++i) {
            // 'twos' keep the bits which appear twice
            twos |= ones & nums[i];

            // 'ones' keep the bits which appear once
            ones ^= nums[i];

            // 'threes' represent whether one bit has appeared three times
            threes = ones & twos;

            // if one bit has appeared three times, we clear the corresponding 'ones' and 'twos'
            ones &= ~threes;
            twos &= ~threes;
        }

        return ones;
    }
};
