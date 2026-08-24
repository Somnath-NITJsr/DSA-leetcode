class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        int candies = n;

        int i = 1;

        while(i < n) {

            if(ratings[i] == ratings[i-1]) {
                i++;
                continue;
            }


            // for increasing slope
            int peak = 0;

            while(ratings[i] > ratings[i-1]) {
                peak++;
                i++;
                candies += peak;

                // reached the last index , means only increasing slope
                if(i == n) {
                    return candies;
                }
            }

            // for decreasing slope
            int dip = 0;

            while(i < n && ratings[i] < ratings[i-1]) {

                dip++;
                i++;
                candies += dip;
            }

            // here we are using the min for - because we are adding every peak as well as the dip, we need to take the max of both , so remove the min peak or dip
            
            candies -= min(dip, peak);

        }



        return candies;






        // // vector<int> L2R(n, 1);
        // // vector<int> R2L(n, 1);

        // vector<int> candies(n, 1);


        // // move left to right
        // for(int i=1; i<n; i++) {

        //     if(ratings[i] > ratings[i-1]) {

        //         // L2R[i] = max(L2R[i], L2R[i-1] + 1);
        //         candies[i] = max(candies[i], candies[i-1] + 1);
        //     }
        // }

        // // move right to left
        // for(int i=n-2; i>=0; i--) {

        //     if(ratings[i] > ratings[i+1]) {

        //         // R2L[i] = max(R2L[i], R2L[i+1] + 1);
        //         candies[i] = max(candies[i], candies[i+1] + 1);
        //     }
        // }

        // int result = 0;

        // for(int i=0; i<n; i++) {

        //     result += candies[i];
        //     // result += max(R2L[i], L2R[i]);
        // }

        // return result;
    }
};