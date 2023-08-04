/* Given an integer array nums, rotate the array
 * to the right by k steps, where k is non-negative.*/

/* this solution uses additional memory to copy
 * elements into their correct places */

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums.size());

        // copy elements into temp
        for (int i = 0; i < nums.size(); ++i) {
            temp[i] = nums[i];
        }

        // rotate
        for (int i = 0; i < nums.size(); ++i) {
            nums[(i+k)%nums.size()] = temp[i];
        }
    }
};
