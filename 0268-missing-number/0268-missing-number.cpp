class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        // Approach 3

        // int result = n;

        // for(int i=0; i<n; i++) {
            
        //     result = result ^ i;
        //     result = result ^ nums[i];
        // }

        // return result;


        // Approach 2
        // long long sum  = accumulate(begin(nums), end(nums), 0LL);

        // long long nSum = n*(n+1)/2;

        // return nSum - sum;



        // Approach 1 - using the binary search alt of linear search
        sort(begin(nums), end(nums));

        int l      = 0;
        int r      = n - 1 ;
        int result = n;

        while(l <= r) {

            int mid = l + (r - l)/2;

            if(nums[mid] > mid) {
                result = mid;
                r      = mid - 1;
            } else {
                l      = mid + 1;
            }
        }
        
        return result;
    }
};