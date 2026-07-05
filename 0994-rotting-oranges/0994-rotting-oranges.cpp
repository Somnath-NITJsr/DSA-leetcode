class Solution {
public:
    typedef pair<int, int> P;
    vector<vector<int> >directions {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int freshOranges = 0;

        queue<P> que;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 2) { // rotten
                    que.push({i, j});
                } else if(grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

        if(freshOranges == 0) {
            return 0;
        }

        // comparator
        auto isSafe = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };
                
        int minutes = 0;
        while(!que.empty()) {

            int N = que.size();

            while(N--) {

                P curr = que.front();
                que.pop();

                int i = curr.first;
                int j = curr.second;

                for(auto& dir: directions) {
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];

                    if(isSafe(i_, j_) && grid[i_][j_] == 1) {
                        que.push({i_, j_});
                        grid[i_][j_] = 2;
                        freshOranges--;
                    }
                }

            }
            minutes++;
        }

        if(freshOranges == 0) {
            return minutes - 1;
        } else {
            return -1;
        }
    }
};