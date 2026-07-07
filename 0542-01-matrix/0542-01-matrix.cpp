class Solution {
public:
    typedef pair<int, int> P;
    vector<vector<int>> directions{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // declare the result vector with all 0s
        vector<vector<int>> result(m, vector<int>(n, -1));

        // declare the queue
        queue<P> q;

        // find the coordinates of all the 0s from the mat
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    result[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // check if the new coordinates are safe
        auto isSafe = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };

        // hit the bfs from that 0s
        while (!q.empty()) {

            P curr = q.front();
            q.pop();

            int x = curr.first;
            int y = curr.second;

            for (auto& dir : directions) {

                int nx = x + dir[0];
                int ny = y + dir[1];

                if (isSafe(nx, ny) && result[nx][ny] == -1) {
                    result[nx][ny] = result[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return result;
    }
};