class Solution {
public:
    void getSubsets(vector<int>& nums, int i, vector<int>& temp, vector<vector<int>>& result) {

        // base case
        if(i == nums.size()) {
            result.push_back(temp);
            return;
        }

        // take
        temp.push_back(nums[i]);

        // explore
        getSubsets(nums, i+1, temp, result);
        temp.pop_back();

        // skip
        getSubsets(nums, i+1, temp, result);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();

        vector<int> temp;
        vector<vector<int>> result;

        getSubsets(nums, 0, temp, result);

        return result;
    }
};