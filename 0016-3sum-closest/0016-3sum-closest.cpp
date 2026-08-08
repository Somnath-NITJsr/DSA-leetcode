class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
    
        if(n == 3) {
            return nums[0] + nums[1] + nums[2];
        }

        int closestSum = 100000;

        sort(begin(nums), end(nums)); 


        for(int k=0; k<n-2; k++) {

            int i = k+1;
            int j = n-1;

            while(i < j) {
                int sum = nums[k] + nums[i] + nums[j];

                if(abs(sum - target) < abs(closestSum - target)) {
                    closestSum = sum;
                }

                if(sum < target) {
                    i++;
                } else {
                    j--;
                }

            }
        }

        return closestSum;
        
    }
};