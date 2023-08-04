/* In this updated code, three boolead arrays are used
 * to keep track of the digits seen in each row, column,
 * and box. The rows array has dimensions[9][9], where
 * rows[i][j] is true if digit j+1 has alreay been seen
 * in row i. Similarly, the columns and boxes arrays
 * store the presence of digits in the respective
 * columns and boxes.
 *
 * By iterating through the board and updating the
 * corresponding arrays, you can efficiently check if
 * any digit is repeated in a row, column, or box. If
 * a digit is already marked as seen in any of these
 * structures, the Sudoku is invalid.
 *
 * This approach avoids the need for repeatedly searching
 * through the sets, resulting in better performance. */


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false};
        bool columns[9][9] = {false};
        bool boxes[9][9] = {false};

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int digit = board[i][j] - '1';
                    int boxIndex = (i / 3) * 3 + (j / 3);

                    if (rows[i][digit] || columns[j][digit] || boxes[boxIndex][digit]) {
                        return false;
                    }

                    rows[i][digit] = true;
                    columns[j][digit] = true;
                    boxes[boxIndex][digit] = true;
                }
            }
        }

        return true;
    }
};

