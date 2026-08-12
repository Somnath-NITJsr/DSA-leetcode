class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        // using the prefix and suffix 

        int prefix  = 1;
        int suffix  = 1;
        int maxProd = INT_MIN;

        for(int i=0; i<n; i++) {

            if(prefix == 0) {
                prefix = 1; // fresh start
            }

            if(suffix == 0) {
                suffix = 1; // fresh start
            }

            prefix *= nums[i];
            suffix *= nums[n-i-1];

            maxProd = max({maxProd, prefix, suffix});
        }

        return maxProd;

        
        
        // BRUTE FORCE -- TLE
        // int maxProd = INT_MIN;

        // for(int i=0; i<n; i++) {
            
        //     for(int j=i; j<n; j++) {

        //         int prod = 1;
        //         for(int k=i; k<=j; k++) {

        //             prod *= nums[k];
        //         }

        //         maxProd = max(maxProd, prod);
        //     }
        // }
        
        // return maxProd;
    }
};