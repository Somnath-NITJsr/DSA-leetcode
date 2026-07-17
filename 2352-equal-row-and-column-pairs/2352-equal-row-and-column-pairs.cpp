class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {

        int n          = grid.size();
        int countPairs = 0;

        for(int row=0; row<n; row++) {
            for(int col=0; col<n; col++) {
                bool isEqual = true;

                for(int i=0; i<n; i++) {

                    if(grid[row][i] != grid[i][col]) {
                        isEqual = false;
                        break;
                    }
                }

                if(isEqual) {
                    countPairs++;
                }
            }
        }
        return countPairs;
    }
};