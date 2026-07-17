class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {

        int n          = grid.size();
        int countPairs = 0;

        map<vector<int>, int> mp;
        // 1
        for(int row=0; row<n; row++) {
            
            // passes the entire vector [3, 2, 1] to the map.
            mp[grid[row]]++;

        }

        // 2
        for(int col=0; col<n; col++) {
            
            vector<int> temp;
            for(int row=0; row<n; row++) {
                temp.push_back(grid[row][col]);
            }
            // the freq will be added to the countPairs
            countPairs += mp[temp];
        }

        return countPairs;
        /*

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
        */
    }
};