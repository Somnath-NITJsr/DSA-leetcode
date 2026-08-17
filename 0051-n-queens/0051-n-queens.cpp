class Solution {
public:
    void solve(vector<string>& board, int row, int& n, vector<vector<string>>& result) {

        if(row >= n) {
            result.push_back(board);
            return;
        }

        auto isSafe = [&](int& col) {

            // check upward
            for(int i=row-1; i>=0; i--) {

                if(board[i][col] == 'Q') {
                    return false;
                }
            }

            // check left diagonal
            for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) {

                if(board[i][j] == 'Q') {
                    return false;
                }
            }

            // check right diagonal
            for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++) {

                if(board[i][j] == 'Q') {
                    return false;
                }
            }

            return true;

        };


        for(int col=0; col<n; col++) {

            if(isSafe(col)) {

                board[row][col] = 'Q';
                
                solve(board, row+1, n, result);

                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        // {". . .", ". . . ", ". . ." }

        vector<vector<string>> result;

        solve(board, 0, n, result);

        return result;
    }
};