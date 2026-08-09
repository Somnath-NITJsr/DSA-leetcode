class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        int currSubSum = nums[0];
        int maxSubSum  = nums[0];

        for(int i=1; i<n; i++) {

            currSubSum = max(currSubSum + nums[i], nums[i]);
            maxSubSum  = max(maxSubSum, currSubSum);
        }

        currSubSum    = nums[0];
        int minSubSum = nums[0];

        for(int i=1; i<n; i++) {
            currSubSum = min(nums[i], currSubSum + nums[i]);
            minSubSum  = min(currSubSum, minSubSum);
        }

        return max(abs(minSubSum), maxSubSum);
    }
};