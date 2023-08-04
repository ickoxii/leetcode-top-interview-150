#ifndef GAME_OF_LIFE_CHATGPT_H
#define GAME_OF_LIFE_CHATGPT_H

/* To make your solution faster, you can optimize the approach
 * by reducint unnecessary iterations and minimizing the number
 * of memory accesses. Here are a few optimizations you can apply:
 *
 * 1. Eliminate unnecessary iterations: instead of iterating
 * over all cells and updating the number of live neighbors for
 * each cell, you can optimize it by only considering the cells
 * that are currently live(1) and their immediate neighbors. 
 * This reduces the number of iterations and unnecessary calculations.
 *
 * 2. Use a state encoding scheme: Instead of directly modifying
 * the 'board' matrix while counting neighbors, you can use
 * a state encoding sceme to indicate the updated state of
 * each cell. For example, you can use additional values like
 * 2 to indicate a cell that was previously live (1) but will
 * become dead (0) in the next state. This eliminates the need
 * for multiple matrix updates during the process.
 *
 * 3. Update the matrix based on the state encoding: After
 * counting the live neighbors and applying the state encoding,
 * you can update the 'board' matrix based on the encoded
 * states in a single pass. This avoids the need for nested
 * switch cases and multiple assignments. */



class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        // Neighbor directions
        vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int liveNeighbors = 0;

                // Count live neighbors
                for (int k = 0; k < 8; ++k) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x >= 0 && x < rows && y >= 0 && y < cols && (board[x][y] == 1 || board[x][y] == 2)) {
                        liveNeighbors++;
                    }
                }

                // Apply state encoding
                if (board[i][j] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)) {
                    board[i][j] = 2; // Cell will become dead in the next state
                } else if (board[i][j] == 0 && liveNeighbors == 3) {
                    board[i][j] = 3; // Cell will become live in the next state
                }
            }
        }

        // Update the board based on the state encoding
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                board[i][j] %= 2; // Restore the original state (0 or 1) from the state encoding (2 or 3)
            }
        }
    }
};

#endif
