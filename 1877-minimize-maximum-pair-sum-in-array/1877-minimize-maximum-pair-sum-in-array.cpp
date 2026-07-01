class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();

        int i = 0, j = n-1;
        int result = 0;

        while(i < j) {

            int ans = nums[i] + nums[j];
            result = max(result, ans);
            i++;
            j--;
        }
        return result;
    }
};