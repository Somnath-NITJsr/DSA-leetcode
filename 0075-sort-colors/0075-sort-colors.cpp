class Solution {
public:
    void sortColors(vector<int>& nums) {

        int n = nums.size();

        int i = 0; // take care for 0
        int j = 0; // take care for 1
        int k = n - 1; // take care for 2

        while(j <= k) {

            if(nums[j] == 0) {

                swap(nums[i], nums[j]);
                i++;
                j++;

            } else if(nums[j] == 2) {

                swap(nums[j], nums[k]);
                k--;

            } else {
                j++;
            }
        }



        
        // int ones = 0;
        // int twos = 0;
        // int zero = 0;


        // for(int i=0; i<nums.size(); i++) {

        //     if(nums[i] == 0) {
        //         zero++;
        //     } else if(nums[i] == 1) {
        //         ones++;
        //     } else {
        //         twos++;
        //     }
        // }

        // for(int i=0; i<zero; i++) {
        //     nums[i] = 0;
        // }

        // for(int i=zero; i<ones+zero; i++) {
        //     nums[i] = 1;
        // }

        // for(int i=ones+zero; i<ones+twos+zero; i++) {
        //     nums[i] = 2;
        // }

        
    }
};