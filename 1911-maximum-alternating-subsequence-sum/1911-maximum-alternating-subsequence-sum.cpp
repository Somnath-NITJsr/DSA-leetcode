class Solution {
public:
    long long solve(vector<int>& nums, int i, int n, vector<vector<long long >>& t, bool flag) {
        if(i >= n) {
            return 0;
        }

        if(t[i][flag] != -1) {
            return t[i][flag];
        }

        long long skip = solve(nums, i+1, n, t, flag);

        long long val  = nums[i];

        if(!flag) {
            val = -val;
        }

        long long take = solve(nums, i+1, n, t, !flag) + val;

        return t[i][flag] = max(take, skip);

    }
    long long maxAlternatingSum(vector<int>& nums) {

        int n = nums.size();

        vector<vector<long>> t(n+1, vector<long>(2, 0));

        for(int i=1; i<n+1; i++) {

            // even +, -, +, -
            t[i][0] = max(t[i-1][1] - nums[i-1], t[i-1][0]);

            // odd   take                          skip
            t[i][1] = max(t[i-1][0] + nums[i-1], t[i-1][1]);
        }

        return max(t[n][0], t[n][1]);

        // int n = nums.size();
        // vector<vector<long long >> t (100000, vector<long long >(2, -1));

        // return solve(nums, 0, n, t, true); // flag is true for even index
    }
};