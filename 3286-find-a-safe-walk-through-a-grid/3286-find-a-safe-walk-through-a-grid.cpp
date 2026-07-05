class Solution {
public:
    vector<vector<int>> directions {{0 ,1}, {1, 0}, {-1, 0}, {0, -1}};

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        deque<pair<int, int>> dq;
        vector<vector<int>> result(m, vector<int>(n, 1e9));
        // result[i][j] = min health to reach the dest

        result[0][0] = grid[0][0]; // source is (0, 0)
        dq.push_front({0 , 0}); // cost, node

        // comparator
        auto isSafe = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };


        while(!dq.empty()) {
            auto& curr = dq.front();

            int row    = curr.first;
            int col    = curr.second;

            dq.pop_front();

            for(auto& dir: directions) {
                int row_ = row + dir[0];
                int col_ = col + dir[1];

                if(isSafe(row_, col_)) {

                    if(result[row][col] + grid[row_][col_] < result[row_][col_]) {
                        result[row_][col_] = result[row][col] + grid[row_][col_];
                        
                        if(grid[row_][col_] == 0) {
                            dq.push_front({row_, col_});
                        } else {
                            dq.push_back({row_, col_});
                        }
                    }
                }
            }
        }
        int x = result[m-1][n-1];
        return (health - x) >= 1;
    }
};