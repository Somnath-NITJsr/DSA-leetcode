class Solution {
public:
    int m, n;
    void dfs(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return;
        }

        // mark visited
        grid[i][j] = 0;

        // hit dfs in all directions
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // apply dfs to the cols
        for(int row=0; row<m; row++) {
            
            // 1st col
            if(grid[row][0] == 1) {
                dfs(grid, row, 0);
            }

            // last col
            if(grid[row][n-1] == 1) {
                dfs(grid, row, n-1);
            }
        }

        // apply dfs to the rows
        for(int col=0; col<n; col++) {

            // 1st row
            if(grid[0][col] == 1) {
                dfs(grid, 0, col);
            }

            // last row
            if(grid[m-1][col] == 1) {
                dfs(grid, m-1, col);
            }
        }

        int count = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    count++;
                }
            }
        }
        return count;
    }
};