class Solution {
public:
    int getJump(vector<int>& nums, vector<int>& t, int idx, int& n) {

        if(idx >= n-1) {
            return 0;
        }

        if(t[idx] != -1) {
            return t[idx];
        }
        
        int mini = 1e9;
        for(int i=1; i<=nums[idx]; i++) {

            mini = min(mini, 1 + getJump(nums, t, idx + i, n));
        }

        return t[idx] = mini;
    }
    int jump(vector<int>& nums) {
        int n     = nums.size();
        vector<int> t(n, -1);

        return getJump(nums, t, 0, n);
    }
};