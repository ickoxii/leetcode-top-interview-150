#ifndef ROTATE_IMAGE_H
#define ROTATE_IMAGE_H
#include <vector>

// solution is approximately O(n)

/* You are given an n x n 2D matrix representing
 * an image, rotate the image by 90 degrees (clockwise).
 *
 * You have to rotate the image in-place, which means 
 * you have to modify the input 2D matrix directly.
 *
 * DO NOT allocate another 2D matrix and do the rotation. */


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // iterate through each layer of the matrix 
        for (int i = 0; i < n / 2; ++i) {
            // iterate through each side of the layer
            for (int j = i; j < n - i - 1; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        }
    }
};

#endif
