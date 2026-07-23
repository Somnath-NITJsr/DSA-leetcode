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

        vector<int> t(n+1);
        // base cases
        t[0] = 0;
        t[1] = nums[0];

        for(int i=2; i<=n; i++) {
            int steal = t[i-2] + nums[i-1];
            int skip  = t[i-1];

            t[i] = max(steal, skip);
        }

        return t[n];
        

        // int t[101];
        // memset(t, -1, sizeof(t));

        // return solve(nums, 0, t, n);
    }
};