class Solution {
public:
    int solve(vector<int>& nums, int i, int p, vector<vector<int>>& t, int& n) {
        if(i >= n) {
            return 0;
        }

        if(p != -1 && t[i][p] != -1) {
            return t[i][p];
        }

        // take 
        int take = 0;
        if(p == -1 || nums[p] < nums[i]) {
            take = 1 + solve(nums, i+1, i, t, n);
        }

        int skip = solve(nums, i+1, p, t, n);

        if(p != -1) {
            t[i][p] = max(take, skip);
        }

        return max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();    
        vector<vector<int>> t(n+1, vector<int>(n+1, -1));

        return solve(nums, 0, -1, t, n);
    }
};