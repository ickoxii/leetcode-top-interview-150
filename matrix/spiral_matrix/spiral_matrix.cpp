// this solution works

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <utility>

using namespace std;

/* Given an m x n matrix, return all elements
 * of the matrix in spiral order. */

class Solution {
private:
    enum { RIGHT, DOWN, LEFT, UP };
    unsigned int nextDirection;
    
    void changeDirection() {
        switch(nextDirection) {
            case RIGHT:
                nextDirection = DOWN;
                break;
            case DOWN:
                nextDirection = LEFT;
                break;
            case LEFT:
                nextDirection = UP;
                break;
            default:
                nextDirection = RIGHT;
                break;
        }
    }

    pair<int, int> getNextLocation(pair<int, int> curr, int& low_row, int& high_row, int& low_col, int& high_col) {
        pair<int, int> nextLocation;
        
        switch(nextDirection) {
            case RIGHT: // right
                if (curr.second + 1 < high_col) {
                    nextLocation.first = curr.first;
                    nextLocation.second = curr.second + 1;
                } else {
                    changeDirection();
                    low_row = curr.first;
                    if (curr.first + 1 < high_row) {
                        nextLocation = getNextLocation(curr, low_row, high_row, low_col, high_col);
                    }
                }
                break;
            case DOWN: // down
                if (curr.first + 1 < high_row) {
                    nextLocation.first = curr.first + 1;
                    nextLocation.second = curr.second;
                } else {
                    changeDirection();
                    high_col = curr.second;
                    if (curr.second - 1 > low_col) {
                        nextLocation = getNextLocation(curr, low_row, high_row, low_col, high_col);
                    }
                }
                break;
            case LEFT: // left
                if (curr.second - 1 > low_col) {
                    nextLocation.first = curr.first;
                    nextLocation.second = curr.second - 1;
                } else {
                    changeDirection();
                    high_row = curr.first;
                    if (curr.first - 1 > low_row) {
                        nextLocation = getNextLocation(curr, low_row, high_row, low_col, high_col);
                    }
                }
                break;
            default: // up
                if (curr.first - 1 > low_row) {
                    nextLocation.first = curr.first - 1;
                    nextLocation.second = curr.second;
                } else {
                    changeDirection();
                    low_col = curr.second;
                    if (curr.second + 1 < high_col) {
                        nextLocation = getNextLocation(curr, low_row, high_row, low_col, high_col);
                    }
                }
                break;
        }

        return nextLocation;
    }


public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        nextDirection = RIGHT;
        int low_row = -1, high_row = matrix.size();
        int low_col = -1, high_col = matrix[0].size();
        int totalvals = matrix.size() * matrix[0].size();
        vector<int> spiral;
        pair<int, int> curr;
        curr.first = curr.second = 0;
        spiral.push_back(matrix[curr.first][curr.second]);

        while (spiral.size() < totalvals) {
            curr = getNextLocation(curr, low_row, high_row, low_col, high_col);
            spiral.push_back(matrix[curr.first][curr.second]);
        }

        return spiral;
    }
};


// Function to generate a random matrix of size rows x cols
vector<vector<int>> generateRandomMatrix(int rows, int cols) {
    vector<vector<int>> matrix(rows, vector<int>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 100; // Random element between 0 and 99
        }
    }

    return matrix;
}

int main() {
    // Seed the random number generator
    srand(time(0));

    Solution solution;

    for (int i = 0; i < 20; ++i) {
        // Generate a random number of rows and columns
        int rows = rand() % 10 + 1; // Random number between 1 and 10
        int cols = rand() % 10 + 1; // Random number between 1 and 10

        // Generate a random matrix
        vector<vector<int>> matrix = generateRandomMatrix(rows, cols);

        // Print the matrix
        cout << "Matrix " << i+1 << ":" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }

        // Test the matrix with the solution
        vector<int> result = solution.spiralOrder(matrix);

        // Print the spiral order result
        cout << "Spiral Order: ";
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;

        cout << "-----------------------" << endl;
    }

    return 0;
};
