#ifndef MAX_AREA_H
#define MAX_AREA_H

/* You are given an integer array height of length n. There
 * are n vertical lines drawn such that the two endpoints
 * of the ith line are (i, 0) and (i, height[i]);.
 *
 * Find two lines that together with the x-axis form a
 * container, such that the container contains the most water.
 * 
 * Return the maximum amount of water a container can store.
 *
 * Notice that you may not slant the container. */

// notes: use a two-pointer approach

class Solution {
public:
    int maxArea(vector<int>& height) {
        // two "pointer" approach using indices
        // keeps track of indices of the max left and right height
        int left = 0, right = height.size() - 1;
        int max_left = height[left], max_right = height[right];
        int max_area = 0, curr_area = 0;

        while(left < right) {
            // update max heights
            max_left = max(max_left, height[left]);
            max_right = max(max_right, height[right]);

            // find current area and update max area if needed
            curr_area = min(max_left, max_right) * (right - left);
            max_area = max(max_area, curr_area);

            // move whichever side is smaller
            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        return max_area;
    }
};

#endif
