class Solution {
public:
    void solve(vector<int>& nums, int i, int& n, vector<int>& temp, vector<vector<int>>& result) {

        if(i > n) {
            return;
        }

        if(i == n) {
            result.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        solve(nums, i+1, n, temp, result);
        temp.pop_back();

        solve(nums, i+1, n, temp, result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();

        vector<int> temp;
        vector<vector<int>> result;

        solve(nums, 0, n, temp, result);
        return result;
    }
};