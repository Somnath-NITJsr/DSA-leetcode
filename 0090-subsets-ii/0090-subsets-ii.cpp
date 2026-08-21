class Solution {
private:
    void getAllSubsets(vector<int>& nums, vector<int>& ans, int i,
                       vector<vector<int>>& allSubsets) {
        // base condition
        if (i == nums.size()) {
            allSubsets.push_back(ans);
            return;
        }
        // inclusion step is same as the subset 1
        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i + 1, allSubsets);

        // exclusion step is special
        // pop back first the previous element that is pushed into the ans
        ans.pop_back();
        int index = i + 1;
        // to avoid getting the duplicates in the array {1,2,2,2,3};
        // we will take 1 2 3 but not 2 2 2 again and again
        while (index < nums.size() && nums[index] == nums[index - 1]) {
            index++;
        }
        getAllSubsets(nums, ans, index, allSubsets);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> allSubsets;
        vector<int> ans;

        getAllSubsets(nums, ans, 0, allSubsets);
        return allSubsets;
    }
};