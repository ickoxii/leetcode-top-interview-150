/**
 * lambda function, according to chatgpt:
 *
 * a lambda function is a special type of function in c++ that
 * you can define inside another function, perfect for small,
 * one-off tasks that would otherwise require creating a
 * separate named function.
 *
 * here is a breakdown of the syntax and its parts:
 *
 * auto inside = [&](int r, int c) { // function body };
 *
 * 'auto' - tells the compiler to automatically determine the
 * type of the variable at compile-time. It is at this time
 * that the compiler determines 'inside' is a lambda function.
 *
 * '&' - the capture clause. it defines what from the surrounding
 * scope should be accessible inside the lambda. The '&' means 
 * that the lambda will capture all local variables used in the
 * lambda by reference.
 *
 * '(int r, int c)' - these are the parameters that will be passed
 * to the lambda when you call it.
 *
 * ' { // function body };' - this is the body of the lambda.
 * It's just like the body of a normal function. It describes
 * what the lambda does.
 * */


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;

        int rows = board.size(), cols = board[0].size();
        queue<pair<int, int>> q;
        
        // so called 'lambda' function
        // for creating a temp function inside another function
        auto inside = [&](int r, int c){ return r >= 0 && r < rows && c >= 0 && c < cols; };
        auto push = [&](int r, int c){
            if(inside(r,c) && board[r][c] == 'O'){
                board[r][c] = '.'; // temporarily mark as '.', will change back to 'O' later
                q.push({r, c});
            }
        };
        
        // start from border cells
        for(int r = 0; r < rows; ++r){
            for(int c = 0; c < cols; ++c){
                if(r == 0 || r == rows-1 || c == 0 || c == cols-1){
                    push(r, c);
                }
            }
        }
        
        // bfs from border 'O's
        while(!q.empty()){
            auto [r, c] = q.front(); q.pop();
            push(r-1, c), push(r+1, c), push(r, c-1), push(r, c+1);
        }
        
        // change 'O' to 'X' and '.' back to 'O'
        for(auto& row : board){
            for(auto& c : row){
                if(c == 'O') c = 'X';
                else if(c == '.') c = 'O';
            }
        }
    }
};
