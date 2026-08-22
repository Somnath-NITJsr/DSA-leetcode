class Solution {
public:
    void solveQueens(vector<string>& board, int row, int& n, vector<vector<string>>& result) {

        if(row >= n) {
            result.push_back(board);
            return;
        }
        

        // here we are checking for the particular column
        auto isSafe = [&](int col) {

            // check upward
            for(int i = row-1; i >= 0; i--) {

                if(board[i][col] == 'Q') {
                    return false;
                }
            }

            // check diagonal left
            for(int i=row-1, j=col-1; i >= 0 && j >= 0; i--, j--) {

                if(board[i][j] == 'Q') {
                    return false;
                }
            }

            // check diagonal right
            for(int i=row-1, j=col+1; i >= 0 && j < n; i--, j++) {

                if(board[i][j] == 'Q') {
                    return false;
                }
            }

            return true;

        };


        // check for the col, where we can place the Queen
        for(int col = 0; col < n; col++) {
            
            // if the col is safe for placing next queen then we can proceed
            if(isSafe(col)) {
                
                // do
                board[row][col] = 'Q';

                // explore
                solveQueens(board, row + 1, n, result);

                // undo
                board[row][col] = '.';
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;

        vector<string> board(n, string(n, '.'));


        solveQueens(board, 0, n, result); // row = 0

        return result;
    }
};