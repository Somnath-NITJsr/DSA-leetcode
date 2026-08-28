class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
        int n = rocks.size();

        vector<int> reqRocks(n, 0);

        for(int i = 0; i < n; i++) {

            int diff = capacity[i] - rocks[i];

            reqRocks[i] = diff;
        }

        sort(begin(reqRocks), end(reqRocks));

        int count = 0;
        for(auto& it: reqRocks) {
            
            if(additionalRocks >= it) {
                
                additionalRocks -= it;
                count++;
            } else {
                break;
            }
        }

        return count;
    }
};