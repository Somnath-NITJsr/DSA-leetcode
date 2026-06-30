class Solution {
public:
    typedef pair<int, pair<int, int> > P;
    vector<vector<int>> directions {{-1,0}, {1, 0}, {0, -1}, {0, 1}};

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        // comparator
        auto isSafe = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };


        // define the result vector
        vector<vector<int>> result(m, vector<int>(n, 1e9));

        // define the priority_queue
        priority_queue<P, vector<P>, greater<P>> pq;

        result[0][0] = 0;
        pq.push({0, {0, 0}}); // difference, {x, y}

        while(!pq.empty()) {

            auto& it = pq.top();
            int diff = it.first;
            int x    = it.second.first;
            int y    = it.second.second;

            pq.pop();

            for(auto& dir: directions) {

                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(isSafe(x_, y_)) {

                    int absDiff = abs(heights[x][y] - heights[x_][y_]);
                    int maxDiff = max(absDiff, diff);

                    if(result[x_][y_] > maxDiff) {
                        result[x_][y_] = maxDiff;

                        pq.push({maxDiff, {x_, y_}});
                    }
                }

            }
        }
        return result[m-1][n-1];
    }
};