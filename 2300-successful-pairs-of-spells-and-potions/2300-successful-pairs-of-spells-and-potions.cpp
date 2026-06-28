class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();

        vector<int> result;
        sort(potions.begin(), potions.end());

        long long minPotions;

        for(int i=0; i<n; i++) {
            minPotions = ceil(((1.0)* success)/spells[i]);

            int l = 0;
            int r = m;

            while(l < r) {

                int mid = l + (r-l)/2;

                if(potions[mid] >= minPotions) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            result.push_back(m - l);
        }

        return result;
    }
};