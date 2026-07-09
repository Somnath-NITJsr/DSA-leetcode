class Solution {
public: 
    void dfs(vector<vector<char>>& grid, int i, int j, int& m, int& n) {
        // base case
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 'O') {
            return;
        }

        // mark visit
        grid[i][j] = '$';

        dfs(grid, i, j+1, m, n);
        dfs(grid, i, j-1, m, n);
        dfs(grid, i-1, j, m, n);
        dfs(grid, i+1, j, m, n);
    }
    void solve(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // hit the dfs for the col
        for(int row=0; row<m; row++) {

            // 1st col
            if(grid[row][0] == 'O') {
                dfs(grid, row, 0, m, n);
            }

            // last col
            if(grid[row][n-1] == 'O') {
                dfs(grid, row, n-1, m, n);
            }
        }

        // hit the dfs for the row
        for(int col=0; col<n; col++) {

            // 1st row
            if(grid[0][col] == 'O') {
                dfs(grid, 0, col, m, n);
            }

            // last row
            if(grid[m-1][col] == 'O') {
                dfs(grid, m-1, col, m, n);
            }
        }


        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 'O') {
                    grid[i][j] = 'X';
                } 
                if(grid[i][j] == '$') {
                    grid[i][j] = 'O';
                }
            }
        }
    }
};