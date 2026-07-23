class Solution {
public:
    int solve(vector<int>& nums, int i, int t[], int& n) {
        if(i >= n) {
            return 0;
        }

        if(t[i] != -1) {
            return t[i];
        }

        int steal = nums[i] + solve(nums, i+2, t, n);
        int skip  = solve(nums, i+1, t, n);

        return t[i] = max(steal, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        int t[101];
        memset(t, -1, sizeof(t));

        return solve(nums, 0, t, n);
    }
};