 /**
  * You are given an n x n integer matrix board where the cells are
  * labeled from 1 to n^2 in a Boustrophedon style starting from the
  * bottom left of the board (i.e. board[n-1][0]) and alternating
  * direction each row.
  *
  * Boustrophedon style (source: Wikipedia)
  *     a style of writing in which alternate lines of writing are
  *     reversed (ie. first line read right to left, then left to right).
  *
  * You start on square 1 of the board. In each move, starting from
  * square curr, do the following:
  *     - Choost a destination square 'next' with a label in the range
  *         [curr+1, min(cur+6, n^2)]
  *         - this choice simulates the result of a standard 6-sided
  *             die roll: i.e., there are always at most 6 destinations,
  *             regardless of the size of the board.
  *     - If 'next' has a snake or ladder, you MUST move to the
  *         destination of that snake or ladder. Otherwise, you move
  *         to 'next'.
  *     - The game ends when you reach the square 'n^2'
  *
  * A board square on row r and column c has a snake or ladder if
  * board[r][c] != -1. The destination of that snake or ladder is
  * board[r][c]. Squares 1 and n^2 do not have a snake or ladder.
  *
  * Note that you only take a snake or ladder at most once per move.
  * If the destination to a snake or ladder is the satrt of another
  * snake or ladder, you do not follow the subsequent snake or ladder.
  *
  * For example, suppose the board is [[-1,4],[-1,3]], and on the 
  * first move, your destination square is 2. You follow the ladder
  * to square 3, but do not follow the subsequent ladder to 4.
  *
  * Return the least number of moves required to reach the square n^2.
  * If it is not possible to reach the square, return -1. */

#include <vector>
#include <random>

using namespace std;

class Solution {
public:
    /* snakesAndLadders
     *
     * This problem finds the minimum number of moves to reach
     * the end of the board. */
    int snakesAndLadders(vector<vector<int> >& board) {
        
    }
};
