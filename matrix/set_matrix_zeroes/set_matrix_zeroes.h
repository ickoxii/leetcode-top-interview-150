#ifndef SET_MATRIX_ZEROES_H
#define SET_MATRIX_ZEROS_H

/* Given an m x n integer matrix matrix, if an 
 * element is 0, set its entire row and column
 * to 0's. you must do in place. */

// my own code, no help from chatgpt

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows_zeroed, cols_zeroed;
        
        if (matrix.empty()) {
            return;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (matrix[r][c] == 0) {
                    rows_zeroed.insert(r);
                    cols_zeroed.insert(c);
                }
            }
        }

        // zero the rows that need to be zeroed
        for (auto iter = rows_zeroed.begin(); iter != rows_zeroed.end(); ++iter) {
            int r = *iter;
            for (int i = 0; i < cols; ++i) {
                matrix[r][i] = 0;
            }
        }

        // zero the columns that need to be zeroed
        for (auto iter = cols_zeroed.begin(); iter != cols_zeroed.end(); ++iter) {
            int c = *iter;
            for (int i = 0; i < rows; ++i) {
                matrix[i][c] = 0;
            }
        }
    }
};

#endif

