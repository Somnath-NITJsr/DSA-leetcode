class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> L2R(n, 1);
        vector<int> R2L(n, 1);


        // move left to right
        for(int i=1; i<n; i++) {

            if(ratings[i] > ratings[i-1]) {

                L2R[i] = max(L2R[i], L2R[i-1] + 1);
            }
        }

        // move right to left
        for(int i=n-2; i>=0; i--) {

            if(ratings[i] > ratings[i+1]) {

                R2L[i] = max(R2L[i], R2L[i+1] + 1);
            }
        }

        int result = 0;

        for(int i=0; i<n; i++) {

            result += max(R2L[i], L2R[i]);
        }

        return result;
    }
};