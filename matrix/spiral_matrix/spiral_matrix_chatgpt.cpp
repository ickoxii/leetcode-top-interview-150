#ifndef SPIRAL_ORDER_H
#define SPIRAL_ORDER_H

#include <vector>
#include <utility>

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiral;

        if (matrix.empty()) {
            return spiral;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();
        int topRow = 0, bottomRow = rows - 1;
        int leftCol = 0, rightCol = cols - 1;

        while (topRow <= bottomRow && leftCol <= rightCol) {
            // Traverse top row from left to right
            for (int col = leftCol; col <= rightCol; ++col) {
                spiral.push_back(matrix[topRow][col]);
            }
            topRow++;

            // Traverse right column from top to bottom
            for (int row = topRow; row <= bottomRow; ++row) {
                spiral.push_back(matrix[row][rightCol]);
            }
            rightCol--;

            // Traverse bottom row from right to left
            if (topRow <= bottomRow) {
                for (int col = rightCol; col >= leftCol; --col) {
                    spiral.push_back(matrix[bottomRow][col]);
                }
                bottomRow--;
            }

            // Traverse left column from bottom to top
            if (leftCol <= rightCol) {
                for (int row = bottomRow; row >= topRow; --row) {
                    spiral.push_back(matrix[row][leftCol]);
                }
                leftCol++;
            }
        }

        return spiral;
    }
};

#endif
