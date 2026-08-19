class Solution {
public:
    // TC: O(N! * N)
    void getPermute(vector<int>& nums, int idx, int& n, vector<vector<int>>& result) {

        if(idx == n-1) {

            result.push_back(nums);
            return;
        }

        unordered_set<int> st;

        for(int i=idx; i<n; i++) {
            
            if(st.find(nums[i]) != st.end()) {
                continue;
            }

            // do something
            st.insert(nums[i]);

            swap(nums[i], nums[idx]);

            // explore
            getPermute(nums, idx+1, n, result);

            // revert back
            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> result;

        getPermute(nums, 0, n, result);

        return result;
    }
};