/* uses sliding window technique
 * 
 * Given an array of positive integers nums and a
 * positive integer target, return the minimal length
 * of a subarray whose sum is greater than or equal
 * to target. If there is no such subarray, return 0
 * instead.
 * */

/*
In this updated code, the sliding window is represented 
by the indices left and right. The window expands by 
moving the right pointer to the right and contracts by 
moving the left pointer to the right. The sum of the 
subarray within the window is continuously adjusted 
based on the positions of the pointers.

By using the sliding window technique, the code avoids 
unnecessary iterations and achieves a linear time 
complexity, resulting in improved performance for 
large inputs.
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLen = INT_MAX;
        int left = 0, sum = 0;

        for (int right = 0; right < n; ++right) {
            sum += nums[right];

            while (sum >= target) {
                minLen = min(minLen, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return (minLen == INT_MAX) ? 0 : minLen;
    }
};

