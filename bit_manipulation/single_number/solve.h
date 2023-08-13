 /** 
  * Given a non-empty array of integers nums, every element appears
  * twice except for one. Find that single one.
  *
  * You must implement a solution with a linear runtime complexity
  * and use only constant extra space. */

/* use XOR:
 * all duplicates will xor each other out, leaving only the one number
 * at the end */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            result ^= nums[i];
        }
        return result;
    }
};
