class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int currSubSum = nums[0];
        int maxSubSum  = nums[0];

        for(int i=1; i<n; i++) {

            currSubSum = max(currSubSum + nums[i], nums[i]);
            maxSubSum  = max(currSubSum, maxSubSum);
        }

        return maxSubSum;
    }
};