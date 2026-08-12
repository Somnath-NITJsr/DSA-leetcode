class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        // Approach 3

        int result = n;

        for(int i=0; i<n; i++) {
            
            result = result ^ i;
            result = result ^ nums[i];
        }

        return result;


        // Approach 2
        // long long sum  = accumulate(begin(nums), end(nums), 0LL);

        // long long nSum = n*(n+1)/2;

        // return nSum - sum;



        // Approach 1
        // sort(begin(nums), end(nums));

        // for(int i=0; i<n; i++) {

        //     if(nums[i] != i) {
        //         return i;
        //     }
        // }
        
        // return n;
    }
};