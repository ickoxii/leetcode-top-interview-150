/* Given n non-negative integers representing an
 * elevation map where the width of each bar is 1,
 * compute how much water it can trap after raining.
 * 
 * ex 1: x designates land, w designates water
 * input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * output: 6
 * 3|
 * 2|       x
 * 1|   xwwwxxwx
 * 0| xwxxwxxxxxx
 *   0123456789...
 *   in this example, 6 units of rain get trapped. */

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>::iterator left, right;
        left = height.begin();
        right = height.end() - 1;
        int left_max = *left, right_max = *right;
        int water = 0;

        while (left < right) {
            if (*left < *right) {
                left_max = max(left_max, *left);
                water += max(left_max-*left, 0);
                left++;
            } else {
                right_max = max(right_max, *right);
                water += max(right_max-*right, 0);
                right--;
            }
        }

        return water;
    }
};
