/* Determine if a 9x9 Sudoku board is valid. Only
 * the filled cells need to be validated according to
 * the following rules:
 *
 * Each row must contain the digits 1-9 without repetition.
 *
 * Each column must contain the digits 1-9 without repetition.
 *
 * Each of the nine 3x3 sub-boxes of the grid must contain
 * the digits 1-9 without repetition.
 *
 * Note:
 * A Sudoku board (partially filled) could be valid but is
 * not necessarily solvable.
 *
 * Only the filled cells need to be validated according
 * to the mentioned rules. */

// solution works

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = 9, col = 9;

        // check rows
        for (int i = 0; i < row; ++i) {
            set<char> seen;
            for (int j = 0; j < col; ++j) {
                if (board[i][j] != '.' && seen.find(board[i][j]) == seen.end()) {
                    seen.insert(board[i][j]);
                } else if (board[i][j] != '.' && seen.find(board[i][j]) != seen.end()) {
                    return false;
                }
            }
        }

        // check columns
        for (int i = 0; i < col; ++i) {
            set<char> seen;
            for (int j = 0; j < row; ++j) {
                if (board[j][i] != '.' && seen.find(board[j][i]) == seen.end()) {
                    seen.insert(board[j][i]);
                } else if (board[j][i] != '.' && seen.find(board[j][i]) != seen.end()) {
                    return false;
                }
            }
        }
 
        // check each box
        for (int box_x = 0; box_x < 3; ++box_x) {
            for (int box_y = 0; box_y < 3; ++box_y) {
                set<char> seen;
                for (int in_x = 0; in_x < 3; ++in_x) {
                    for (int in_y = 0; in_y < 3; ++in_y) {
                        int r = (box_x * 3) + in_x;
                        int c = (box_y * 3) + in_y;
                        if (board[r][c] != '.' && seen.find(board[r][c]) == seen.end()) {
                            seen.insert(board[r][c]);
                        } else if (board[r][c] != '.' && seen.find(board[r][c]) != seen.end()) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};
