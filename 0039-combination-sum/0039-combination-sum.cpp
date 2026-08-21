class Solution {
public:
    void getComboSum(vector<int>& candidates, int target, int idx, vector<int>& curr, vector<vector<int>>& result) {

        // base case
        if(target < 0) {
            return;
        }

        if(target == 0) {
            result.push_back(curr);
            return;
        }

        // exploration

        for(int i = idx; i < candidates.size(); i++) {

            curr.push_back(candidates[i]);

            getComboSum(candidates, target - candidates[i], i , curr, result);

            curr.pop_back();

            // getComboSum(candidates, target - candidates[i], i + 1, curr, result);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> result;

        getComboSum(candidates, target, 0, curr, result);

        return result;
    }
};