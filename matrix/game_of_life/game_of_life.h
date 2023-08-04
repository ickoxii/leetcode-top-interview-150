#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

/* According to Wikipedia's article: "The Game of Life,
 * also known simply as Life, is a cellular automaton
 * devsed by the British mathematician John Horton Conway
 * in 1970."
 *
 * The board is made up of an m x n grid of cells,
 * where each cell has an initial state: live (represented
 * by a 1) or dead (represented by a 1). Each cell
 * interacts with its eight neighbors (horizontal, vertical,
 * diagonal) using the following four rules:
 *
 * 1. Any live cell with fewer than two live neighbors
 * dies through under-population.
 * 
 * 2. Any live cell with two or three live neighbors lives
 * on to the next generation.
 * 
 * 3. Any live cell with more than three live neighbors
 * dies by over-population
 *
 * 4. Any dead cell with exactly three live neighbors becomes
 * a live cell, as if by reproduction.
 *
 * The next state is created by applying the above rules
 * simultaneously to every cell in the current state,
 * where births and deaths occur simultaneously.
 * Given the current state of the m x n grid board,
 * return the next state. */

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int r = board.size(), c = board[0].size();
        vector<vector<int>> neighbors(r, vector<int>(c, 0));

        // find the number of neighbors for each cell
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (board[i][j] == 1) {
                    // update number of live neighbors
                    for (int x = max(0, i-1); x < min(r, i+2); ++x) {
                        for (int y = max(0, j-1); y < min(c, j+2); ++y) {
                            if (x != i || y != j) {
                                neighbors[x][y]++;
                            }
                        }
                    }
                }
            }
        }

        // update cells
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (board[i][j] == 0) {
                    if (neighbors[i][j] == 3) {
                        board[i][j] = 1;
                    }
                }
                else {
                    switch(neighbors[i][j]) {
                        case 0:
                        case 1:
                            board[i][j] = 0;
                            break;
                        case 2:
                        case 3:
                            break;
                        default:
                            board[i][j] = 0;
                            break;
                    }
                }
            }
        }
    }
};

#endif

