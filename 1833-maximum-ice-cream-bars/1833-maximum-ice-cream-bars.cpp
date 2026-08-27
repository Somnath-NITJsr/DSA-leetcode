class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int count = 0;

        sort(begin(costs), end(costs));

        for(int i=0; i<costs.size(); i++) {

            if(coins >= costs[i]) {
                coins -= costs[i];
                count++;
            }
        }
        return count;
    }
};