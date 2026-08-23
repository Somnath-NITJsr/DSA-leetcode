class Solution {
public:
    bool getJump(vector<int>& nums, int idx, int& n, vector<int>& t) {

        if(idx >= n - 1) {
            return true;
        }

        if(t[idx] != -1) {
            return t[idx];
        }

        for(int i=1; i<=nums[idx]; i++) { // nums[idx] means the possibilites for jump

            if(getJump(nums, idx + i, n, t)) {
                return t[idx] = true;
            }
        }

        return t[idx] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        // New Approach
        int maxReachable = nums[0];

        for(int i=1; i<n; i++) {

            if(i > maxReachable) {
                return false;
            }

            maxReachable = max(maxReachable, nums[i] + i);
        }

        return true;

        // vector<int> t(n, -1);
        // return getJump(nums, 0, n, t);

    }
};