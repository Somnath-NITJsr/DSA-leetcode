class Solution {
public:
    int count;
    vector<vector<int>> directions {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    void dfs(vector<vector<int>>& grid, int i, int j, int& m, int& n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            count++;
            return;
        }
        
        if (grid[i][j] == -1) {
            return;
        }

        grid[i][j] = -1; // marked visited

        dfs(grid, i, j+1, m, n);
        dfs(grid, i, j-1, m, n);
        dfs(grid, i+1, j, m, n);
        dfs(grid, i-1, j,m ,n);
    }

    int bfs(vector<vector<int>>& grid, int i, int j, int& m, int& n) {
        int perimeter = 0;

        queue<pair<int, int> > q;
        q.push({i, j});
        grid[i][j] = -1; // marked visited

        while(!q.empty()) {
            auto& it = q.front();

            int x = it.first;
            int y = it.second;
            q.pop();

            for(auto& dir: directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if(nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == 0) {
                    perimeter++;
                } else if(grid[nx][ny] == -1) {
                    continue;
                } else {
                    q.push({nx, ny});
                    grid[nx][ny] = -1;
                }
            }
        }
        return perimeter;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        count = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    dfs(grid, i, j, m, n);
                    return count;
                    // return bfs(grid, i, j, m, n);
                }
            }
        }
        return -1;
    }
};