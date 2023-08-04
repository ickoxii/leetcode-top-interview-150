 /**
  * Given an m x n matrix boars containing 'X' and 'O',
  * capture all regions that are 4-directionally surrounded
  * by 'X'.
  *
  * A region is captured by flipping all 'O's into 'X's in
  * that surrounded region. */

class Solution {
    /**
     * validLoc
     *
     * checks to see if a location is within the bounds
     * of the board.
     *
     * parameters:
     * board - m x n matrix board
     * r, c - indices of the current element
     *
     * return:
     * true - [r, c] is inside the board
     * false - [r, c] is outside the board */
    bool validLoc(const vector<vector<char>>& board, int r, int c) {
        return r >= 0 && r < board.size() && c >= 0 && c < board[0].size();
    }

    /**
     * bfs
     * 
     * grabs the index on the top of the queue, pushes its
     * neighbors to the queue, then returns the current index
     * we may only traverse UP, DOWN, LEFT, and RIGHT
     *
     * parameters:
     * q - queue containing the elements to traverse to
     * board - the given m x n board
     * c - character we are looking for
     *     this can be changed depending on our need
     *
     * return:
     * returns a pair [row, column] of the next element to
     * traverse to, or [-1, -1] if none exist */
    pair<int, int> bfs(queue<pair<int, int>>& q, vector<vector<char>>& board, char c) {
        const int MAX_ROW = board.size(), MAX_COL = board[0].size();

        if (q.empty()) return make_pair(-1, -1); // should never execute

        pair<int, int> curr = q.front();
        q.pop();

        int row = curr.first, col = curr.second;
            
        // right
        if (validLoc(board, row+1, col) && board[row+1][col] == c)
            q.push(make_pair(row+1,col));
        // down
        if (validLoc(board, row, col+1) && board[row][col+1] == c)
            q.push(make_pair(row,col+1));
        // left
        if (validLoc(board, row-1, col) && board[row-1][col] == c)
            q.push(make_pair(row-1,col));
        // up
        if (validLoc(board, row, col-1) && board[row][col-1] == c)
            q.push(make_pair(row,col-1));

        return curr;
    }

public:
    /**
     * solve
     *
     * this function 'captures' regions of 'O's which are
     * surrounded by 'X's. The algorithm first traverses through
     * the edge of the board, running a dfs on any encountered 
     * 'O's and converting these regions to a temporary character
     * '.'. Then a second pass is done on the board, going
     * through the inside region. Any 'O' encountered in this
     * region will be turned into an 'X'. A final traversal is
     * done through the board, and all '.' are turned back into
     * 'O's.
     *
     * parameters:
     * board - the given m x n matrix
     *
     * return:
     * none */
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if (rows == 0) return;
        int cols = board[0].size();

        if (rows < 3 || cols < 3) return;

        pair<int, int> p;
        queue<pair<int, int>> q; // for bfs
        char c = 'O'; // current search char

        /*
        * traverse board once
        * if any 'O's exist on the edge, dfs and mark these locations
        * for changing later */
        // top
        for (int i = 0; i < cols; ++i) {
            if (board[0][i] == 'O') {
                board[0][i] = '.';
                p = new pair<int, int>(0, i);
                q.push(p);
                
                while (!q.empty()) {
                    p = dfs(q,board,'O');
                    board[p->first][p->second] = '.';
                }
            }
        }
        
        // bottom
        for (int i = 0; i < cols; ++i) {
            if (board[rows-1][i] == 'O') {
                board[rows-1][i] = '.';
                p = new pair<int, int>(rows-1, i);
                q.push(p);
                
                while (!q.empty()) {
                    p = dfs(q,board,'O');
                    board[p->first][p->second] = '.';
                }
            }
        }
       
        // left
        for (int i = 0; i < rows; ++i) {
            if (board[i][0] == 'O') {
                board[i][0] = '.';
                p = new pair<int, int>(i,0);
                q.push(p);
                
                while (!q.empty()) {
                    p = dfs(q,board,'O');
                    board[p->first][p->second] = '.';
                }
            }
        }
       
        // right
        for (int i = 0; i < rows; ++i) {
            if (board[i][cols-1] == 'O') {
                board[i][cols-1] = '.';
                p = new pair<int, int>(i,cols-1);
                q.push(p);
                
                while (!q.empty()) {
                    p = dfs(q,board,'O');
                    board[p->first][p->second] = '.';
                }
            }
        }
        
        // iterate through inner section and convert
        // 'O's to 'X's
        for (int r = 1; r < rows-1; ++r) {
            for (int c = 1; c < cols-1; ++c) {
                if (board[r][c] == 'O')
                    board[r][c] = 'X';
            }
        }

        // convert the temporary '.'s back to 'O's
        // top
        for (int i = 0; i < cols; ++i) {
            if (board[0][i] == '.') {
                board[0][i] = 'O';
                p = new pair<int, int>(0, i);
                q.push(p);
                
                while (!q.empty()) {
                    p = dfs(q,board,'.');
                    board[p->first][p->second] = 'O';
                }
            }
        }
        
        // bottom
        for (int i = 0; i < cols; ++i) {
            if (board[rows-1][i] == '.') {
                board[rows-1][i] = 'O';
                p = new pair<int, int>(rows-1, i);
                q.push(p);
                
                while (!q.empty()) {
                    p = dfs(q,board,'.');
                    board[p->first][p->second] = 'O';
                }
            }
        }
       
        // left
        for (int i = 0; i < rows; ++i) {
            if (board[i][0] == '.') {
                board[i][0] = 'O';
                p = new pair<int, int>(i,0);
                q.push(p);
                
                while (!q.empty()) {
                    p = dfs(q,board,'.');
                    board[p->first][p->second] = 'O';
                }
            }
        }
       
        // right
        for (int i = 0; i < rows; ++i) {
            if (board[i][cols-1] == '.') {
                board[i][cols-1] = 'O';
                p = new pair<int, int>(i,cols-1);
                q.push(p);
                
                while (!q.empty()) {
                    p = dfs(q,board,'.');
                    board[p->first][p->second] = 'O';
                }
            }
        }

    }
};
