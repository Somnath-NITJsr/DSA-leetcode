class Solution {
public:
    typedef pair<int, int> P;
    vector<vector<int>> directions {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> height(m, vector<int>(n, -1));
        queue<P> que;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(isWater[i][j] == 1) { // water cell
                    height[i][j] = 0; // this is a source for bfs
                    que.push({i, j});
                }
            }
        }

        auto isSafe = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };

        while(!que.empty()) {

            int N = que.size();

            while(N--) {
                auto& curr = que.front();
                int i      = curr.first;
                int j      = curr.second;

                que.pop();
                for(auto& dir : directions) {
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];

                    if(isSafe(i_, j_) && height[i_][j_] == -1) {
                        height[i_][j_] = height[i][j] + 1;
                        que.push({i_, j_});
                    }
                }

            }
        }
        return height;
    }
};